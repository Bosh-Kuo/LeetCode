/*
time complexity: O(n)
tags: Array, Hash Table, Bit Manipulation, Trie
note: 每個整數都可以用 32 位元的 2 進制來表示，而所有整數的 2 進制表示可以集中在一個 Trie 來管理，
Node 由上到下儲存數字的 MSB 到 LSB。由於 2 進制表示法中，一個位元只可能為 0 or 1，因此我們令 Node->child[0] 代表 bit = 0，
Node->child[1] 代表 bit = 1。
先將所有整數 insert 進 Trie，Trie的每個遍歷路徑都代表一個整數的二進制表示。再逐整數從 MSB 與 Trie Node 比較，
如果該整數在該位數的 bit = 0，且 TrieNode->child[1] 存在，則代表該整數與某個數在位數 i  XOR 的結果為 1，那麽該兩數 XOR 的答案必定包含 2^i，
反之 bit = 1，且 TrieNode->child[0] 存在時也一樣。
*/

class BitTrie
{
public:
    BitTrie *child[2];

    BitTrie()
    {
        this->child[0] = nullptr; // for bit = 0
        this->child[1] = nullptr; // for bit = 1
    }
};

class Solution
{
public:
    BitTrie *rootNode;
    void insertNumToBitTrie(int num)
    {
        BitTrie *currentNode = rootNode;
        bitset<32> numInBit(num);

        // from the most significant bit (MSB)  to the least significant bit (LSB).
        for (int i = 31; i >= 0; i--)
        {
            int bit = numInBit[i];
            if (!currentNode->child[bit])
                currentNode->child[bit] = new BitTrie();
            currentNode = currentNode->child[bit];
        }
    }
    int findMaxXOR(int num)
    {
        int maxXOR = 0;
        BitTrie *currentNode = rootNode;
        bitset<32> numInBit(num);

        // from the most significant bit (MSB)  to the least significant bit (LSB).
        for (int i = 31; i >= 0; i--)
        {
            int bit = numInBit[i];
            int target = bit == 0 ? 1 : 0;
            // 1^1 = 0, 1^0 = 1, 0^1 = 1, 0^0 = 0
            if (currentNode->child[target])
            {
                maxXOR += (1 << i);
                currentNode = currentNode->child[target];
            }
            else
                currentNode = currentNode->child[bit];
        }
        return maxXOR;
    }
    int findMaximumXOR(vector<int> &nums)
    {
        rootNode = new BitTrie();
        for (int num : nums)
            insertNumToBitTrie(num);
        int answer = 0;
        for (int num : nums)
            answer = max(answer, findMaxXOR(num));
        return answer;
    }
};