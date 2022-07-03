#include <iostream>
#include <vector>

using namespace std;

// TC : O(n * log(n))
// Aux Space : O(n)

bool comp(pair<int, int> &a, pair<int, int> &b) {

    if (a.first == b.first)
        return a.second < b.second;

    return a.first < b.first;
}

int min_rooms(vector<vector<int>> times) {
    int n = times.size();
    vector<pair<int, int>> timeline;

    for (int i = 0; i < n; ++i) {
        timeline.push_back({times[i][0], +1});
        timeline.push_back({times[i][1], -1});
    }

    sort(timeline.begin(), timeline.end(), comp);

    int current_meeting = 0;
    int max_meeting = 0;

    for (int i = 0; i < (2*n); ++i) {
        current_meeting += timeline[i].second;
        max_meeting = max(max_meeting, current_meeting);
    }

    return max_meeting;
}

int main() {
    cout<<min_rooms({{0,30},{5,10},{15,20}})<<endl;
    cout<<min_rooms({{1,18},{18,23},{15,29},{4,15},{2,11},{5,13}})<<endl;
}