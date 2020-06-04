/**
 * (BEGIN009) STL-set-任二數之和 : 
 * 輸入數列，每列為一個測試案例。
 * 每一個案例內含數個數字。
 * 請將每個案例內的數字，任選兩個數字(可重複)相加，將所有可能由小到大輸出。 
 * 
 * 標準輸入：
 * 1 2 2 8 5 7 7 6 6 7 3 5
 * 2 9 6 3 1 4 1 8
 * 8 0 1 1 3 7 7 4 5 3 2
 * 2 8 7 1 7 1 7 1 8 7 1
 * 0 9 6 4 1
 * 9 3 9 2 2 2
 * 8 5 8 9 3 6 6 2
 * 5 0 7 6 0 1 2 8 9 2 9 9 3 0
 * 4 0 3 6 6 6 2 1 1
 * 9 7 8 6 3 5 7 1
 * 0 0 6 7 8 0 6 1 1 0 1 5
 * 9 3 5 2 7 9 8 9 5 8 4
 * 3 8 2 0 0 1 7 7 4 5 4 2
 * 4 5 6 6 5 2 6
 * 5 3 0 2 8 3 7 1000014643 1000000927 1000011427 1000027245
 * 
 * 標準輸出:
 * 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16↵\r\n
 * 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18↵\r\n
 * 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16↵\r\n
 * 2 3 4 8 9 10 14 15 16↵\r\n
 * 0 1 2 4 5 6 7 8 9 10 12 13 15 18↵\r\n
 * 4 5 6 11 12 18↵\r\n
 * 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18↵\r\n
 * 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18↵\r\n
 * 0 1 2 3 4 5 6 7 8 9 10 12↵\r\n
 * 2 4 6 7 8 9 10 11 12 13 14 15 16 17 18↵\r\n
 * 0 1 2 5 6 7 8 9 10 11 12 13 14 15 16↵\r\n
 * 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18↵\r\n
 * 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16↵\r\n
 * 4 6 7 8 9 10 11 12↵\r\n
 * 0 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 1000000927 1000000929 1000000930 1000000932 1000000934 1000000935 1000011427 1000011429 1000011430 1000011432 1000011434 1000011435 1000014643 1000014645 1000014646 1000014648 1000014650 1000014651 1000027245 10000272...(行後省略)↵\r\n
 * 
*/

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    string s;
    while (getline(cin, s))
    {

        istringstream sin(s);
        vector<int> a; //vector可以不預設長度，動態新增資料
        __int64 v;     //64位元長度的變數，用來存巨量測資

        while (sin >> v)
            a.push_back(v);

        set<__int64> sum; //宣告方式跟vector類似，此使用set sum作為集合聯集的資料結構
        for (int k = 0; k < a.size(); k++)
            for (int h = k; h < a.size(); h++) //用加法表的概念就能理解，兩數相加不必計算重複的部分
                sum.insert(a[k] + a[h]);       //將兩數之和塞進set裡面

        for (set<__int64>::iterator p = sum.begin(); p != sum.end(); p++) //iterator類似pointer 可以宣告為特定容器型態的iterator
        {
            if (p != sum.begin())
            {
                cout << " ";
            }

            cout << (*p); //set會自動將元素排序，達到題目要求的小到大輸出  回憶：BST
        }
        cout << endl;
    }
}
