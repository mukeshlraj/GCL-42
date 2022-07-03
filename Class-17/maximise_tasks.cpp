#include <iostream>
#include <vector>

using namespace std;

int get_max_task(vector<int> times, int total_time) {

    sort(times.begin(), times.end());

    for (int i = 0; i < times.size(); ++i) {
        if (times[i] <= total_time) {
            total_time -= times[i];
        } else {
            return i;
        }
    }
    return times.size();
}

int main() {
    cout<<get_max_task({4,2,1,2,5},8)<<endl;
    cout<<get_max_task({3,2,1,2,5},8)<<endl;
}