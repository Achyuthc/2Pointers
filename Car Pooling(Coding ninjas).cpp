/*You are working as a cab driver. Your car moves in a straight line and moves toward the forward direction only. Initially, you have ‘C’ empty seats for the passengers.
Now, you are given ‘N’ number of trips that you have to make. In each trip, you are given three integers ‘Num’, ‘pickPoint’, and ‘dropPoint’ denoting that there are ‘Num’ numbers of passengers standing at 'pickpoint’ and you have to drop them at 'droppoint’.
Your task is to find if it is possible to pick up and drop off all the passengers of all the given trips or not.*/

#include <bits/stdc++.h>
static bool comp(pair<int,int> a,pair<int,int> b)
{
	return a.first<b.first;
}

bool carPooling(vector<vector<int> > trips, int n, int c)
{
    // Write Your Code Here.
	vector<pair<int,int>> pick,drop;
	for(int i=0;i<n;i++)
	{
		pick.push_back({trips[i][1],trips[i][0]});
		drop.push_back({trips[i][2],trips[i][0]});
	}
	sort(pick.begin(),pick.end(),comp);
	sort(drop.begin(),drop.end(),comp);
	int i=0,j=0,passenger=0;
	while(i<n)
	{
		passenger+=pick[i].second;
		while(pick[i].first>=drop[j].first)
		{
			passenger-=drop[j].second;
			j++;
		}
		i++;
		if(passenger>c)
			return false;
	}
	return true;
	
}
