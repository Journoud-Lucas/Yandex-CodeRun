#include <iostream>
#include <vector>
#include <set>

int main()
{
    int N;
    int nbVoucher = 0;
    std::cin >> N;
    std::vector<int> cost(N);
    std::multiset<std::pair<int, int>> ms;


    for (int i = 0; i < N; ++i)
    {
        std::cin >> cost[i];
    }

    int sum = 0;

    for (auto actualCost : cost) // We calculate the number of potential vouchers and the total cost without use.
    {
        sum += actualCost;
        if (actualCost >= 100)
        {
            nbVoucher++;
        }
    }

   
    int usedVoucher = 0, remainingVoucher = 0;

    std::vector<int> dayOfUsingVoucher;
    int numberToStock = nbVoucher;

    for (int i = cost.size() - 1; i >= 0; --i) // We go through the table backwards
    {
        if (cost[i] < 100)
        {
            ms.insert({cost[i], i+1}); 
            if (ms.size() > numberToStock)
            {
                ms.erase(*ms.begin());
            }
            // We store the X largest numbers less than 100
            // X being the number of vouchers we may potentially encounter later on
        }
        else
        {
            if (!ms.empty()) // If you are on a voucher and there are available days to delete
            {
                // We reduce the total amount to be paid by removing the most expensive item from those stored.
                // We then remove it from the multiset so that it is not used 21 times.
                // We add the day we just removed to dayOfUsingVoucher so that it can be displayed in the output.
                // We remove one voucher from availability. 
                sum -= ms.rbegin()->first;
                dayOfUsingVoucher.push_back(ms.rbegin()->second);
                ms.erase(*ms.rbegin());
                nbVoucher--;
            }
            // Whether we used the voucher or not, we just used one, so that's one less we'll encounter later on.
            numberToStock--;
        }
    }

/*

Test 0:
5
35
40
101
59
63

Output:
235
0 1
5

Test 1:
4
100
78
4
170

Output:
274
1 1
2

Test 2:
8
35
40
101
59
63
50
100
90

Expected output:
385
0 2
5
8
*/
    std::cout << sum << std::endl;
    std::cout << nbVoucher << " " << dayOfUsingVoucher.size() << std::endl;
    for(int i = dayOfUsingVoucher.size() - 1; i >= 0; --i)
    {
        std::cout << dayOfUsingVoucher[i] << std::endl;
    }

    return 0;
}