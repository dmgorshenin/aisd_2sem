#include <vector>
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>
using namespace std;
using minutes = chrono::minutes;
using milliseconds = chrono::milliseconds;

struct stats {
    unsigned long comparison_count = 0;
    unsigned long copy_count = 0;
};

stats bubble_sort(vector<int>::iterator begin, vector<int>::iterator end) {
    stats stat;
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (auto it = begin; it != end - 1; ++it) {
            if (*it > *(it + 1)) {
                int temp = *it;
                stat.copy_count++;
                *it = *(it + 1);
                stat.copy_count++;
                *(it + 1) = temp;
                stat.copy_count++;
                swapped = true;
                
            }
            stat.comparison_count++;
        }
    }
    return stat;
}

stats cocktail_sort(vector<int>::iterator begin, vector<int>::iterator end) {
    stats stat;
    bool swapped = true;
    end = end - 1;
    while (swapped) {
        swapped = false;
        for (auto it = begin; it < end; ++it) {
            if (*it > *(it + 1)) {
                int temp = *it;
                stat.copy_count++;
                *it = *(it + 1);
                stat.copy_count++;
                *(it + 1) = temp;
                stat.copy_count++;
                swapped = true;
                
            }
            stat.comparison_count++;
        }
        if (!swapped) {
            break;
        }
        swapped = false;
        --end;
        for (auto it = end; it != begin; --it) {
            if (*it < *(it - 1)) {
                int temp = *it;
                stat.copy_count++;
                *it = *(it - 1);
                stat.copy_count++;
                *(it - 1) = temp;
                stat.copy_count++;
                swapped = true;
                
            }
            stat.comparison_count++;
        }
        ++begin;
    }
    return stat;
}

stats comb_sort(vector<int>::iterator begin, vector<int>::iterator end) {
    stats stat;
    int gap = distance(begin, end);
    double shrink = 1.3;
    bool swapped = true;
    while (gap > 1 or swapped) {
        gap = floor(gap / shrink);
        if (gap < 1) {
            gap = 1;
        }
        swapped = false;
        auto it1 = begin;
        auto it2 = it1 + gap;
        while (it2 != end) {
            if (*it1 > *it2) {
                int temp = *it1;
                stat.copy_count++;
                *it1 = *it2;
                stat.copy_count++;
                *it2 = temp;
                stat.copy_count++;
                swapped = true;
                
            }
            stat.comparison_count++;
            ++it1;
            ++it2;
            stat.comparison_count++;
        }
    }
    return stat;
}

vector<int> randomVector(size_t size)
{
    vector<int> v(size);
    random_device r;
    generate(v.begin(), v.end(), [&] {return r(); });
    return v;
}

pair<double,double> AVG(vector<stats> vec) {
    double avg_copy = 0, avg_compar = 0;
    for (auto i : vec) {
        avg_copy += i.copy_count;
        avg_compar += i.comparison_count;   
    }
    avg_compar /= 100;
    avg_copy /= 100;
    return { avg_copy, avg_compar };
}




void random_bubble(int N) {
    vector<stats> stat_vector;
    auto start_time = chrono::steady_clock::now();
    for (size_t i = 0; i < 100; ++i) {
        vector<int> v(randomVector(N));
        stats s = bubble_sort(v.begin(),v.end());
        stat_vector.push_back(s);
        cout << "|";
    }
    auto end_time = chrono::steady_clock::now();
    auto duration = chrono::duration_cast<minutes>((end_time - start_time)/100);
    pair<double,double> copy = AVG(stat_vector);
    cout <<endl<< "Random vector "<<N<<" values bubble : " << copy.first << "\t" << copy.second<<"\t"<<duration << endl;
}

void random_cocktail(int N) {
    vector<stats> stat_vector;
    auto start_time = chrono::steady_clock::now();
    for (size_t i = 0; i < 100; ++i) {
        vector<int> v(randomVector(N));
        stats s = cocktail_sort(v.begin(), v.end());
        stat_vector.push_back(s);
        cout << "|";
    }
    auto end_time = chrono::steady_clock::now();
    auto duration = chrono::duration_cast<minutes>((end_time - start_time) / 100);
    pair<double, double> copy = AVG(stat_vector);
    cout << endl << "Random vector "<<N<<" values cocktail : " << copy.first << "\t" << copy.second << "\t" << duration << endl;
}

void random_comb(int N) {
    vector<stats> stat_vector;
    auto start_time = chrono::steady_clock::now();
    for (size_t i = 0; i < 100; ++i) {
        vector<int> v(randomVector(N));
        stats s = comb_sort(v.begin(), v.end());
        stat_vector.push_back(s);
        cout << "|";
    }
    auto end_time = chrono::steady_clock::now();
    auto duration = chrono::duration_cast<milliseconds>(end_time - start_time) / 100;
    pair<double, double> copy = AVG(stat_vector);
    cout << endl << "Random vector "<<N<<" values comb : " << copy.first << "\t" << copy.second << "\t" << duration << endl;
}

void sorted_bubble(int N) {
    vector<int> v(randomVector(N));
    sort(v.begin(), v.end());
    auto start_time = chrono::steady_clock::now();
    stats s = bubble_sort(v.begin(),v.end());
    auto end_time = chrono::steady_clock::now();
    auto duration = chrono::duration_cast<minutes>((end_time - start_time) / 100);
    cout << "Sort vector "<<N<<" values bubble : " << s.copy_count << "\t" << s.comparison_count << "\t" << duration << endl;
}

void sorted_cocktail(int N) {
    vector<int> v(randomVector(N));
    sort(v.begin(), v.end());
    auto start_time = chrono::steady_clock::now();
    stats s = cocktail_sort(v.begin(),v.end());
    auto end_time = chrono::steady_clock::now();
    auto duration = chrono::duration_cast<minutes>((end_time - start_time) / 100);
    cout << "Sort vector "<<N<<" values coctail : " << s.copy_count << "\t" << s.comparison_count << "\t" << duration << endl;
}

void sorted_comb(int N) {
    vector<int> v(randomVector(N));
    sort(v.begin(), v.end());
    auto start_time = chrono::steady_clock::now();
    stats s = comb_sort(v.begin(), v.end());
    auto end_time = chrono::steady_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>((end_time - start_time) / 100);
    cout << "Sort vector " << N << " values comb : " << s.copy_count << "\t" << s.comparison_count << "\t" << duration << endl;
}

void back_sorted_bubble(int N) {
    vector<int> v(randomVector(N));
    sort(v.begin(), v.end(), greater<int>());
    auto start_time = chrono::steady_clock::now();
    stats s = bubble_sort(v.begin(), v.end());
    auto end_time = chrono::steady_clock::now();
    auto duration = chrono::duration_cast<minutes>((end_time - start_time) / 100);
    cout << "Back sorted vector "<<N<<" values bubble : " << s.copy_count << "\t" << s.comparison_count << "\t" << duration << endl;
}

void back_sorted_cocktail(int N) {
    vector<int> v(randomVector(N));
    sort(v.begin(), v.end(), greater<int>());
    auto start_time = chrono::steady_clock::now();
    stats s = cocktail_sort(v.begin(), v.end());
    auto end_time = chrono::steady_clock::now();
    auto duration = chrono::duration_cast<minutes>((end_time - start_time) / 100);
    cout << "Back sorted vector "<<N<<" values cocktail : " << s.copy_count << "\t" << s.comparison_count << "\t" << duration << endl;
}

void back_sorted_comb(int N) {
    vector<int> v(randomVector(N));
    sort(v.begin(), v.end(), greater<int>());
    auto start_time = chrono::steady_clock::now();
    stats s = comb_sort(v.begin(), v.end());
    auto end_time = chrono::steady_clock::now();
    auto duration = chrono::duration_cast<milliseconds>(end_time - start_time);
    cout << "Back sorted vector " << N << " values comb : " << s.copy_count << "\t" << s.comparison_count << "\t" << duration << endl;
}


int main() {
    /*stats s_1k_random, s_2k_random, s_3k_random, s_5k_random, s_10k_random, s_25k_random, s_50k_random, s_100k_random;*/
    vector<stats> stat_vector;

    //random_bubble(1000);
    //random_bubble(2000);
    //random_bubble(3000);
    //random_bubble(5000);
    //random_bubble(10000);
    //random_bubble(25000);
    //random_bubble(50000);
    //random_bubble(100000);

    /*random_cocktail(1000);
    random_cocktail(2000);
    random_cocktail(3000);
    random_cocktail(5000);
    random_cocktail(10000);
    random_cocktail(25000);
    random_cocktail(50000);
    random_cocktail(100000);*/

    random_comb(1000);
    random_comb(2000);
    random_comb(3000);
    random_comb(5000);
    random_comb(10000);
    random_comb(25000);
    random_comb(50000);
    random_comb(100000);

    //sorted_bubble(1000);
    //sorted_bubble(2000);
    //sorted_bubble(3000);
    //sorted_bubble(5000);
    //sorted_bubble(10000);
    //sorted_bubble(25000);
    //sorted_bubble(50000);
    //sorted_bubble(100000);

   /* sorted_cocktail(1000);
    sorted_cocktail(2000);
    sorted_cocktail(3000);
    sorted_cocktail(5000);
    sorted_cocktail(10000);
    sorted_cocktail(25000);
    sorted_cocktail(50000);
    sorted_cocktail(100000);*/

    sorted_comb(1000);
    //sorted_comb(2000);
    //sorted_comb(3000);
    //sorted_comb(5000);
    //sorted_comb(10000);
    //sorted_comb(25000);
    //sorted_comb(50000);
    //sorted_comb(100000);

  /*  back_sorted_bubble(1000);
    back_sorted_bubble(2000);
    back_sorted_bubble(3000);
    back_sorted_bubble(5000);
    back_sorted_bubble(10000);*/
   /* back_sorted_bubble(25000);
    back_sorted_bubble(50000);
    back_sorted_bubble(100000);*/

    //back_sorted_cocktail(1000);
    //back_sorted_cocktail(2000);
    //back_sorted_cocktail(3000);
    //back_sorted_cocktail(5000);
    //back_sorted_cocktail(10000);
    //back_sorted_cocktail(25000);
    //back_sorted_cocktail(50000);
    //back_sorted_cocktail(100000);

    //back_sorted_comb(1000);
    //back_sorted_comb(2000);
    //back_sorted_comb(3000);
    //back_sorted_comb(5000);
    //back_sorted_comb(10000);
   /* back_sorted_comb(25000);
    back_sorted_comb(50000);
    back_sorted_comb(100000);*/

}