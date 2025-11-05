#include<iostream>
#include<list>
#include<vector>
using std::vector;
using std::list;

int main()
{
    list<int> lints = {1,2,3,4,5,6,7};
    vector<int> vints = {-1,-2,-3,-4,-5,-6,-7};

    vector<double> from_lints(lints.begin(), lints.end());
    vector<double> from_vints(vints.begin(), vints.end());

    return EXIT_SUCCESS;
}