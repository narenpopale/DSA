// There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.
// In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.
// Your score is the sum of the points of the cards you have taken.
// Given the integer array cardPoints and the integer k, return the maximum score you can obtain.


// TC - O(N)
// SC - O(1)


#include <bits/stdc++.h>
using namespace std;


int maxScore(vector<int> &cardPoints, int k)
{
    // Initialize variables to store the total sum of card points
    // and the current sum for the sliding window.
    int total_sum = 0, curr_sum = 0;

    // Get the number of cards.
    int n = cardPoints.size();

    // Calculate the total sum of all card points.
    for (int i = 0; i < n; i++)
    {
        total_sum += cardPoints[i];

        // Calculate the initial sum of the first n-k cards.
        if (i < n - k)
        {
            curr_sum += cardPoints[i];
        }
    }

    // If we need to take all cards, return the total sum.
    if (n == k)
    {
        return total_sum;
    }

    // Initialize variables for the sliding window.
    int start = 0, end = n - k - 1;
    int max_score = 0;

    // Use a sliding window to find the maximum score.
    while (end < n)
    {
        // Update the maximum score if the current score is larger.
        max_score = max(max_score, total_sum - curr_sum);

        // Move the window to the right by increasing 'end'.
        end++;

        // Update the current sum by adding the next card to the right.
        if (end < n)
        {
            curr_sum += cardPoints[end];
        }

        // Update the current sum by removing the card from the left.
        curr_sum -= cardPoints[start];

        // Move the window to the right by increasing 'start'.
        start++;
    }

    return max_score;
}
