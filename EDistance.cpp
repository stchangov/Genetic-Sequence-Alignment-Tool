//  Copyright 2024 Stephan Tchangov
#include "EDistance.hpp"
#include <deque>
#include <algorithm>

EDistance::EDistance(const std::string& s1, const std::string& s2) :
           _sequence1(s1), _sequence2(s2) {
     _dp.resize(_sequence1.size() + 1,
                std::vector<int>(_sequence2.size() + 1, 0));
}

int EDistance::penalty(char a, char b) {
    return (a == b) ? 0 : 1;
}

int EDistance::min3(int a, int b, int c) {
    return std::min(a, std::min(b, c));
}

int EDistance::optDistance() {
    const int m = _sequence1.size();
    const int n = _sequence2.size();

    const int gapSize = 2;

    // Base cases
    for (int i = 0; i <= m; ++i) _dp[i][0] = i * gapSize;
    for (int j = 0; j <= n; ++j) _dp[0][j] = j * gapSize;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            int top = _dp[i - 1][j];
            int diagonal = _dp[i - 1][j - 1];
            int left = _dp[i][j - 1];

            if (_sequence1[i - 1] ==
                _sequence2[j - 1]) {  // If the characters match
                _dp[i][j] = _dp[i - 1][j - 1];
            } else {
                int costTop = top + gapSize;
                int costDiagonal = diagonal +
                                penalty(_sequence1[i - 1], _sequence2[j - 1]);
                int costLeft = left + gapSize;

                _dp[i][j] = min3(costTop, costDiagonal, costLeft);
            }
        }
    }

    return _dp[m][n];
}

std::string EDistance::alignment() {
    int i = _sequence1.size();
    int j = _sequence2.size();

    const int gapCost = 2;

    std::deque<char> alignedSeq1;
    std::deque<char> alignedSeq2;
    std::deque<int> costs;

    while (i > 0 || j > 0) {
        char char1 = (i > 0) ? _sequence1[i - 1] : '-';
        char char2 = (j > 0) ? _sequence2[j - 1] : '-';

        if (_dp[i][j] == _dp[i - 1][j - 1] + penalty(char1, char2)) {
            alignedSeq1.push_front(char1);
            alignedSeq2.push_front(char2);
            costs.push_front(penalty(char1, char2));
            --i;
            --j;
        } else if (_dp[i][j] == _dp[i - 1][j] + gapCost) {  // Top move
            alignedSeq1.push_front(char1);
            alignedSeq2.push_front('-');
            costs.push_front(gapCost);
            --i;
        } else {  // Left Move
            alignedSeq1.push_front('-');
            alignedSeq2.push_front(char2);
            costs.push_front(gapCost);
            --j;
        }
    }

    std::string finalAlignment;
    while (!alignedSeq1.empty() && !alignedSeq2.empty() && !costs.empty()) {
        char char1 = alignedSeq1.front();
        char char2 = alignedSeq2.front();
        int cost = costs.front();

        alignedSeq2.pop_front();
        alignedSeq1.pop_front();
        costs.pop_front();

        finalAlignment += char1;
        finalAlignment += ' ';
        finalAlignment += char2;
        finalAlignment += ' ';
        finalAlignment += std::to_string(cost);
        finalAlignment += '\n';
    }

    return finalAlignment;
}
