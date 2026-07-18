/*
ABC 467 - Obesity

Problem Statement
The BMI of a person is calculated as:
  weight[kg] / height[m] / height[m]

In Japan, a person whose BMI is 25 kg/m^2 or more is considered obese.
Given a person's height H in centimeters and weight W in kilograms,
determine whether the person is considered obese in Japan.

Constraints
  - 1 <= H <= 300
  - 1 <= W <= 300
  - All input values are integers

Input
  H W

Output
  Print Yes if the person is obese, otherwise print No.

Sample Input 1
  180 60

Sample Output 1
  No

Sample Input 2
  182 188

Sample Output 2
  Yes

Sample Input 3
  180 81

Sample Output 3
  Yes
*/

#include<iostream>
using namespace std;

int main()
{
    int H; int W;
    cin>>H>>W;

    // always avoid floating point calculations
    if(W * 10000 >= 25 * H * H)
    {
        cout<<"Yes\n";
    }

    else
    {
        cout<<"No\n";
    }

    return 0;
}
