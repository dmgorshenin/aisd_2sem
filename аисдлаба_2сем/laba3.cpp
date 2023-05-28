#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>
#include <unordered_set>
#include <functional>
using namespace std;

const double INF = 1e9;

template<typename Vertex, typename Distance = double>
class Graph {
public:
	struct Edge {
		Vertex from, to;
		Distance distance;
		Edge(const Vertex& f = Vertex(), const Vertex& t = Vertex(), const Distance& d = Distance()) : from(f), to(t), distance(d) {}
		friend bool operator==(const Edge& lhs, const Edge& rhs) {
			return lhs.from == rhs.from and lhs.to == rhs.to and lhs.distance == rhs.distance;
		}
	};
private:
	unordered_map<Vertex, list<Edge>> _data;
public:
	Graph(size_t size=15) :_data(size) {}
	bool has_vertex(const Vertex& v) const {
		return _data.find(v) != _data.end();
	}
	bool add_vertex(const Vertex& v) {
		if (has_vertex(v)) return false;
		_data.insert({ v, {} });
		return true;
	}
	bool remove_vertex(const Vertex& v) {
		if (!has_vertex(v)) return false;
		_data.erase(v);
		for (auto i : _data) {
			for (auto j = i.second.begin(); j != i.second.end();) {
				if ((*j).to == v) {
					j = i.second.erase(j);
				}
				else { ++j; }
			}
		}
		return true;
	}
	unique_ptr<vector<Vertex>> vertices() const {
		vector<Vertex> result;
		for (const auto& i : _data) {
			result.push_back(i.first);
		}
		return make_unique<vector<Vertex>>(result);
	}
	bool add_edge(const Vertex& from, const Vertex& to, const Distance& d) {
		if (!has_vertex(from) or !has_vertex(from)) return false;
		_data.find(from)->second.push_back({ from, to, d });
		return true;
	}
	bool remove_edge(const Vertex& from, const Vertex& to) {
		if (!has_vertex(from) or !has_vertex(to)) {
			return false;
		}
		auto& list = _data.find(from)->second;
		for (const auto& cur: list) {
			if (cur.from == from and cur.to == to) {
				list.remove(cur);
				return true;
			}
		}
		return false;
	}
	bool remove_edge(const Edge& e) {
		if (!has_vertex(e.from) or !has_vertex(e.to)) return false;
		auto& list = _data.find(e.from)->second;
		for (const auto& cur : list) {
			if (cur.from == e.from and cur.to == e.to and cur.distance == e.distance) {
				list.remove(cur);
				return true;
			}
		}
		return false;
	}
	bool has_edge(const Vertex& from, const Vertex& to) const {
		if(!has_vertex(from) or !has_vertex(to)) return false;
		const auto& list = _data.find(from)->second;
		for (const auto& cur : list) {
			if (cur.from == from and cur.to == to) {
				return true;
			}
		}
		return false;
	}
	bool has_edge(const Edge& e) const {
		if (!has_vertex(e.from) or !has_vertex(e.to)) return false;
		const auto& list = _data.find(e.from)->second;
		for (const auto& cur : list) {
			if (cur.from == e.from and cur.to == e.to and cur.distance == e.distance) {
				return true;
			}
		}
		return false;
	}
	unique_ptr<vector<Edge>> edges(const Vertex& v) const {
		if(!has_vertex(v)) throw invalid_argument("Invalid vertex");
		vector<Edge> result;
		const auto& list = _data.find(v)->second;
		for (const auto& cur : list) {
			result.push_back(cur);
		}
		return make_unique<vector<Edge>>(result);
	}
	size_t order() const {
		return _data.size();
	}
	size_t degree(const Vertex& v) const {
		if (!has_vertex(v)) throw invalid_argument("Invalid vertex");
		vector<Edge> e;
		const auto& list = _data.find(v)->second;
		for (const auto& cur : list) {
			e.push_back(cur);
		}
		return e.size();
	}

	unique_ptr<vector<Edge>> shortest_path(const Vertex& from, const Vertex& to) const {
		unordered_map<Vertex, Distance> distances;
		unordered_map<Vertex, Vertex> previous;
		priority_queue<pair<Distance, Vertex>, vector<pair<Distance, Vertex>>, greater<pair<Distance, Vertex>>> queue;

		auto ptr = vertices();

		for (const auto& vertex : *ptr) {
			distances[vertex] = numeric_limits<Distance>::max();
		}
		distances[from] = 0;
		queue.push({ 0, from });

		size_t iterations = 0;
		const size_t max_iterations = order()*(order() - 1)/2;

		while (!queue.empty()) {
			Vertex current = queue.top().second;
			queue.pop();

			for (const auto& edge : _data.at(current)) {
				Distance new_distance = distances[current] + edge.distance;
				if (new_distance < distances[edge.to]) {
					distances[edge.to] = new_distance;
					previous[edge.to] = current;
					queue.push({ new_distance, edge.to });
				}
			}

			iterations++;
			if (iterations > max_iterations) {
				throw runtime_error("Negative cycle detected (or graph contains unreachable vertices)");
			}
		}

		vector<Edge> result;
		Vertex current = to;
		while (previous.find(current) != previous.end()) {
			Vertex prev = previous[current];
			for (const auto& edge : _data.at(prev)) {
				if (edge.to == current) {
					result.push_back(edge);
					break;
				}
			}
			current = prev;
		}
		reverse(result.begin(), result.end());
		return make_unique<vector<Edge>>(move(result));
	}

	vector<Vertex>  walk(const Vertex& start) const {
		vector<Vertex> result;
		queue<Vertex> q;
		unordered_map<Vertex, bool> visited;
		auto& ptr = vertices();

		for (const auto& v : *ptr) {
			visited[v] = false;
		}
		q.push(start);
		visited[start] = true;
		while (!q.empty()) {
			Vertex current = q.front();
			q.pop();
			result.push_back(current);
			for (const auto& edge : _data.at(current)) {
				Vertex neighbor = edge.to;
				if (!visited[neighbor]) {
					q.push(neighbor);
					visited[neighbor] = true;
				}
			}
		}
		return result;
	}

	void walk(const Vertex& start, function<void(const Vertex&)> action) const {
		queue<Vertex> q;
		unordered_map<Vertex, bool> visited;
		auto ptr = vertices();

		for (const auto& v : *ptr) {
			visited[v] = false;
		}
		q.push(start);
		visited[start] = true;
		while (!q.empty()) {
			Vertex current = q.front();
			q.pop();
			action(current);
			for (const auto& edge : _data.at(current)) {
				Vertex neighbor = edge.to;
				if (!visited[neighbor]) {
					q.push(neighbor);
					visited[neighbor] = true;
				}
			}
		}
	}

	Vertex find_vertex_max_average() const {
		if (_data.empty()) {
			throw runtime_error("Graph is empty.");
		}

		Vertex result;
		Distance max_edge = numeric_limits<Distance>::lowest();

		for (const auto& i : _data) {
			Vertex current_vertex = i.first;

			Distance total_distance = 0;
			size_t incoming_edge_count = 0;

			auto ptr_vertex = vertices();

			for (const auto& v : *ptr_vertex) {
				auto ptr_edge = edges(v);
				for (const auto& edge : *ptr_edge) {
					if (edge.to == current_vertex) {
						total_distance += edge.distance;
						incoming_edge_count++;
					}
				}
			}

			if (incoming_edge_count > 0) {
				Distance average = total_distance / incoming_edge_count;
				if (average > max_edge) {
					max_edge = average;
					result = current_vertex;
				}
			}
		}

		return result;
	}

	static void print(const Vertex& v){
		cout << v << "\t";
	}
};

//int main() {
//	Graph<char, int> graph;
//	graph.add_vertex('e');
//	graph.add_vertex('r');
//	graph.add_edge('e', 'r', 4);
//	graph.walk('e', Graph<char,int>::print);
//	graph.remove_vertex('e');
//	graph.remove_vertex('r');
//
//
//	graph.add_vertex('s');
//	graph.add_vertex('t');
//	graph.add_vertex('x');
//	graph.add_vertex('y');
//	graph.add_vertex('z');
//	graph.add_edge('s', 't', 6);
//	graph.add_edge('t', 'x', 5);
//	graph.add_edge('x', 't', -2);
//	graph.add_edge('t', 'y', 8);
//	graph.add_edge('s', 'y', 7);
//	graph.add_edge('y', 'x', -3);
//	graph.add_edge('t', 'z', -4);
//	graph.add_edge('y', 'z', 9);
//	graph.add_edge('z', 's', 2);
//	graph.add_edge('z', 'x', 7);
//
//	cout <<endl<< graph.order()<<"\t"<<graph.degree('t')<<endl;
//
//	auto distances = graph.shortest_path('s', 'z');
//	int min_dist = 0;
//	for (const auto& distance : *distances) {
//		cout << distance.distance<<"\t";
//		min_dist += distance.distance;
//	}
//	cout <<endl << min_dist << endl;
//
//	graph.walk('y', Graph<char, int>::print);
//	cout << endl<<graph.find_vertex_max_average();
//}
//
