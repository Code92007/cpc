#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canAchieve(vector<int>& arr, int x, int operations) {
    int n = arr.size();
    vector<int> c = arr; // 复制数组
    int totalCost = 0;
    
    // 检查从第0位到第x位是否都能设置为1
    for (int bit = x; bit >= 0; bit--) {
        int mask = 1 << bit;
        bool hasBit = false;
        
        // 检查是否已经有数字在这一位为1
        for (int i = 0; i < n; i++) {
            if (c[i] & mask) {
                hasBit = true;
                break;
            }
        }
        
        if (!hasBit) {
            // 没有数字在这一位为1，需要找一个数字来设置这一位
            vector<int> c(n);
            int maxVal = -1;
            int maxIdx = -1;
            
            // 计算每个数字与 (2^bit - 1) 的按位与结果
            int bitMask = (1 << bit) - 1;
            for (int i = 0; i < n; i++) {
                c[i] = c[i] & bitMask;
                if (c[i] > maxVal) {
                    maxVal = c[i];
                    maxIdx = i;
                }
            }
            
            if (maxIdx == -1) {
                return false; // 没有可用的数字
            }
            
            // 计算代价：2^bit - maxVal
            int cost = (1 << bit) - maxVal;
            totalCost += cost;
            
            if (totalCost > operations) {
                return false; // 超过了允许的操作次数
            }
            
            // 将这个数字标记为已使用
            c[maxIdx] = 0;
        }
    }
    
    return true;
}

int solve(vector<int>& arr, int operations) {
    int n = arr.size();
    
    // 二分答案：找到最大的x，使得第0到x位都能设置为1
    int left = -1, right = 30;
    int maxX = -1;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        if (canAchieve(arr, mid, operations)) {
            maxX = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    // 计算最终答案
    int result = 0;
    
    // 第0到maxX位都贡献1
    if (maxX >= 0) {
        result += maxX + 1;
    }
    
    // 计算第(maxX+1)到30位的贡献
    int orResult = 0;
    for (int x : arr) {
        orResult |= x;
    }
    
    // 统计第(maxX+1)到30位中为1的位数
    for (int bit = maxX + 1; bit <= 30; bit++) {
        if (orResult & (1 << bit)) {
            result++;
        }
    }
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, q;
        cin >> n >> q;
        
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        for (int i = 0; i < q; i++) {
            int b;
            cin >> b;
            cout << solve(arr, b) << "\n";
        }
    }
    
    return 0;
}