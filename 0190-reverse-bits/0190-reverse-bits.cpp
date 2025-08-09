class Solution {
public:
    int reverseBits(int n) {
        uint32_t ans = 0;
        for (int i = 0; i < 32; i++, n >>= 1) {
            ans <<= 1;
            ans |= n & 1;
        }
        return ans;
    }
};