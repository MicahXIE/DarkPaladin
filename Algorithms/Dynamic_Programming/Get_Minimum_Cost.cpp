/*
You want to buy public transport tickets for the upcoming month.
You know exactly the days on which you will be travelling.
The month has 30 days and there are three types of ticket:

1-day ticket, costs 2, valid for one day;
7-day ticket, costs 7, valid for seven consecutive days (e.g. if the first valid day is X, then the last valid day is X+6);
30-day ticket, costs 25, valid for all thirty days of the month.
You want to pay as little as possible.

You are given a sorted (in increasing order) array A of dates when you will be travelling. For example, given:

A[0] = 1
A[1] = 2
A[2] = 4
A[3] = 5
A[4] = 7
A[5] = 29
A[6] = 30

You can buy one 7-day ticket and two 1-day tickets. The two 1-day tickets should be used on days 29 and 30.
The 7-day ticket should be used on the first seven days of the month.
The total cost is 11 and there is no possible way of paying less.

Write a function:

class Solution { public int solution(int[] a); }

that, given a zero-indexed array A consisting of N integers that specifies days on which you will be traveling, returns the minimum amount of money that you have to spend on tickets for the month.

For example, given the above data, the function should return 11, as explained above.

Assume that:
-N is an integer within the range [0..30];

-each element of array A is an integer within the range [1..30];

-array A is sorted in increasing order;

-the elements of A are all distinct.
*/

int solution(std::vector <int> &v)
{

	if (v.size() <= 3) return v.size() * 2;
	if (v.size() >= 23) return 25;

    // stInd vector position flag
    // vdind deque position flag
	int stInd = 0;
	int vdind = 0;

	std::vector <std::deque <int>> vdecs = { { v[0] } };

	for (size_t i = 1; i < v.size(); ++i)
	{
		// find the max consecutive days
		if (vdecs[vdind].size() >= 3 &&
			vdecs[vdind].size() <= 6 &&
			v[i] - v[stInd] > 6 &&
			i + 1 < v.size() &&
			v[i + 1] - v[stInd + 1] <= 6
			)
		{
			vdecs[vdind].pop_front();
			stInd++;
			vdecs[vdind].push_back(v[i]);
			continue;
		}

		if (v[i] - v[stInd] <= 6) {

			vdecs[vdind].push_back(v[i]);
		}
		else {
			vdecs.push_back({});
			vdind++;
			vdecs[vdind].push_back(v[i]);
			stInd = i;
		}

	}

	int result = 0;
	int decCnt = 0;
	for (auto i = vdecs.cbegin(); i != vdecs.cend(); ++i)
	{
		// calculate the number of seven days tickets price
		if (i->size() >= 4) {
			result += 7;
			decCnt += i->size();
		}

	}
       
    // add the number of two days tickets price
	result += (v.size() - decCnt) * 2;

}

