#include <iostream>
#include <vector>

// x |= (1 << n); записать 1 в бит Ќ
// x &= ~(1 << n); записать 0
// if (x & (1 << n)) {  /* во n-й бит вписана единица */ }

#define bit 6
std::vector<bool> ToBin(int num)
{
    std::vector<bool> res;
    res.resize(bit);
    res.clear();
    while (num > 0)
    {
        res.push_back(num % 2);
        num /= 2;
    }
    while (res.size() < bit)
        res.push_back(0);
    return res;
}
int ToDec(std::vector<bool> n)
{
    int res = 0;
    for (int i = 0; i < bit; i++)
    {
        res += n[i] * pow(2, i);
    }
    return res;
}
void GiveNum(unsigned short& x, int index, int num)
{
    std::vector<bool> tmp = ToBin(num);
    std::vector<bool> nums;
    nums.resize(bit);
    nums.clear();
    for (int i = 0; i < bit; i++)
    {
        nums.push_back(tmp[bit - 1 - i]);
    }
    for (int i = 0; i < bit; i++)
    {
        if (nums[i])
        {
            x |= (1 << (bit * index + i));
        }
        else
        {
            x &= ~(1 << (bit * index + i));
        }
    }

}
int GetNum(unsigned short x, int index)
{
    std::vector<bool> num;
    num.resize(bit);
    num.clear();
    std::vector<bool> tmp;
    tmp.resize(bit);
    tmp.clear();
    for (int i = 0; i < bit; i++)
    {
        if (x & (1 << (bit * index + i)))
        {
            tmp.push_back(1);
        }
        else
        {
            tmp.push_back(0);
        }

    }
    for (int i = 0; i < bit; i++)
    {
        num.push_back(tmp[bit - i - 1]);
    }
    return ToDec(num);

}
int main()
{
    unsigned short x = 0;
    GiveNum(x, 1, 63);
    GiveNum(x, 0, 12);
    std::cout << GetNum(x, 0) << "\n";
    std::cout << GetNum(x, 1) << "\n";
}
