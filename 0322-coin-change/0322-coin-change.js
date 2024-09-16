/**
 * @param {number[]} coins
 * @param {number} amount
 * @return {number}
 */
var coinChange = function (coins, amount) {
    let dp = Array(amount + 1).fill(Infinity);
    dp[0] = 0;
    for (let currentAmount = 1; currentAmount <= amount; currentAmount++) {
        for (let coin of coins) {
            if (coin <= currentAmount) {
                dp[currentAmount] = Math.min(dp[currentAmount], 1 + dp[currentAmount - coin])
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
};