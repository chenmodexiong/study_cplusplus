//#include <functional>
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <string>
//using namespace std;
//int main() {
//    string s1;
//    getline(cin, s1);
//    vector<int> v1;
//    v1.push_back(0);
//    for (int i = 0; i < s1.size(); ++i) {
//        if (s1[i + 1] != s1[i] + 1 || i == (s1.size() - 1)) {
//            v1.push_back(i);
//        }
//    }
//    vector<int> v2;
//    for (int i = v1.size()-1; i > 0; --i) {
//        int length = v1[i] - v1[i - 1];
//        v2.push_back(length);
//    }
//    sort(v2.begin(), v2.end());
//    int lengthMax = v2[v2.size() - 1];
//    int pos = 0;
//    for (int i = s1.size()-1; i >= 0; --i) {
//        if ((s1[i + 1] - s1[i]) == lengthMax) {
//            pos = i - 1;
//            break;
//        }
//    }
//    for (int i = v1[pos]; i <= v1[pos + 1]; ++i) {
//        cout << s1[i];
//    }
//}
//#include <iostream>
//#include <string>
//using namespace std;
//bool Test(string& s1) {
//    string::iterator begin = s1.begin();
//    string::iterator end = s1.end() - 1;
//    while (begin <= end) {
//        if (*begin == *end) {
//            begin++, end--;
//        }
//        else
//            return false;
//    }
//    return true;
//}
//int main() {
//    string s1, s2;
//    int ret = 0;
//    getline(cin, s1);
//    getline(cin, s2);
//    int pos = 0;
//    while (pos < s1.size()) {
//        string tmp(s1);
//        tmp.insert(pos, s2.c_str());
//        if (Test(tmp)) { ret++; }
//        pos++;
//    }
//    cout << ret << endl;
//}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    /*int i = 0;
    while (cin >> v[i++]);*/
    vector<int> v2;
    int pos = 0;
    while (pos < v.size()) {
        int sum = 0;
        sum += v[pos];
        for (int i = pos; i < v.size(); ++i) {
            if (i + 1 < v.size() && (v[i + 1] - 1 == v[i] || v[i + 1] + 1 == v[i])) {
                sum += v[i + 1];
            }
            else {
                pos = i + 1;
                break;
            }
        }
        v2.push_back(sum);
    }
    sort(v2.begin(), v2.end());
    cout << v2[v2.size() - 1] << endl;
}