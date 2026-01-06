#include<iostream>
#include <vector>
#include <set>
#include <tuple>
#include <unordered_map>
using namespace std;
class MovieRentingSystem {
public:
    unordered_map<long long,int>shop_movie_to_price;
    unordered_map<int,set<pair<int,int>>>unrented_movie_to_price_shop;
    set<tuple<int,int,int>>rented_movies;
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto &e:entries){
            int shop=e[0],movie=e[1],price=e[2];
            shop_movie_to_price[1LL*shop<<32|movie]=price;//把shop和movie分别放在高32位和低32位了
            unrented_movie_to_price_shop[movie].emplace(price,shop);
        }
    }
    
    vector<int> search(int movie) {
        auto it=unrented_movie_to_price_shop.find(movie);
        if(it==unrented_movie_to_price_shop.end()){
            return {};
        }
        vector<int>ans;
        for(auto&[_,shop]:it->second){
            ans.push_back(shop);
            if(ans.size()==5)break;
        }
        return ans;
    }
    
    void rent(int shop, int movie) {
        int price=shop_movie_to_price[1LL*shop<<32|movie];
        unrented_movie_to_price_shop[movie].erase({price,shop});
        rented_movies.emplace(price,shop,movie);
    }
    
    void drop(int shop, int movie) {
        int price=shop_movie_to_price[1LL*shop<<32|movie];
        rented_movies.erase({price,shop,movie});
        unrented_movie_to_price_shop[movie].emplace(price,shop);
    }
    
    vector<vector<int>> report() {
        vector<vector<int>>ans;
        for(auto&[_,shop,movie]:rented_movies){
            ans.push_back({shop,movie});
            if(ans.size()==5)break;
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */