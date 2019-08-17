#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

pair<deque<int>, long> ms_swaps(deque<int> arr, long swaps) {
  long new_swaps = swaps;

  if (arr.size() <= 1) {
    return make_pair(arr, swaps);
  }
  else if (arr.size() == 2) {
    if (arr[0] > arr[1]) {
      sort(arr.begin(), arr.end());
      return make_pair(arr, swaps + 1);
    }
    return make_pair(arr, swaps);
  }

  deque<int> part0, part1;

  pair<deque<int>, long> res0 = ms_swaps({arr.begin(), arr.begin() + arr.size() / 2}, 0);
  pair<deque<int>, long> res1 = ms_swaps({arr.begin() + arr.size() / 2, arr.end()}, 0);

  part0 = res0.first;
  part1 = res1.first;

  new_swaps += res0.second;
  new_swaps += res1.second;

  // handle ting
  while (part0.size() > 0 || part1.size() > 0) {
    if (part0.size() > 0 && part1.size() > 0 && part1[0] < part0[0]) {
      new_swaps += part0.size();
      part1.pop_front();
    }
    else if (part0.size() > 0 && part1.size() > 0) {
      part0.pop_front();
    }
    else {
      break;
    }
  }

  sort(arr.begin(), arr.end());

  return make_pair(arr, new_swaps);
}

// Complete the countInversions function below.
long countInversions(vector<int> arr) {
  pair<deque<int>, long> ans = ms_swaps({arr.begin(), arr.end()}, 0);
  return ans.second;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        long result = countInversions(arr);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
