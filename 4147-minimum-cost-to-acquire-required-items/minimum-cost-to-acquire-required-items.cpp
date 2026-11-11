class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long c1 = cost1;
        long long c2 = cost2;
        long long cb = costBoth;
        long long n1 = need1;
        long long n2 = need2;
        long long cost_individual = (n1 * c1) + (n2 * c2);

        long long overlap = std::min(n1, n2);
        long long cost_mixed = (overlap * cb) + ((n1 - overlap) * c1) + ((n2 - overlap) * c2);

        long long max_need = std::max(n1, n2);
        long long cost_pure_bundle = max_need * cb;

        return min({cost_individual, cost_mixed, cost_pure_bundle});
    }
};