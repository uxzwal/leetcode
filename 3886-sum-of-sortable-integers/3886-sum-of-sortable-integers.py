import random

class Solution:
    def sortableIntegers(self, nums: list[int]) -> int:
        n = len(nums)
        sorted_nums = sorted(nums)
        
        # 1. Find all divisors of n
        divisors = []
        for i in range(1, int(n**0.5) + 1):
            if n % i == 0:
                divisors.append(i)
                if i * i != n:
                    divisors.append(n // i)
                    
        # 2. Map each unique number to a random 64-bit integer for multiset hashing
        unique_vals = set(nums)
        # Use a deterministic seed or standard random to avoid collisions
        rng = random.Random(42)
        val_to_hash = {val: rng.getrandbits(64) for val in unique_vals}
        
        # 3. Compute prefix sums for multiset hashes
        pref_hash_nums = [0] * (n + 1)
        pref_hash_sorted = [0] * (n + 1)
        for i in range(n):
            pref_hash_nums[i + 1] = pref_hash_nums[i] + val_to_hash[nums[i]]
            pref_hash_sorted[i + 1] = pref_hash_sorted[i] + val_to_hash[sorted_nums[i]]
            
        # 4. Compute prefix sums for adjacent drops in nums
        pref_drops = [0] * n
        for i in range(n - 1):
            pref_drops[i + 1] = pref_drops[i] + (1 if nums[i] > nums[i + 1] else 0)
            
        # 5. Check each divisor k
        ans = 0
        for k in divisors:
            possible = True
            for i in range(n // k):
                L = i * k
                R = L + k
                
                # Check condition 1: Multiset equality via hash matching
                hash_A = pref_hash_nums[R] - pref_hash_nums[L]
                hash_S = pref_hash_sorted[R] - pref_hash_sorted[L]
                if hash_A != hash_S:
                    possible = False
                    break
                    
                # Check condition 2: At most 1 drop (cyclically sorted)
                internal_drops = pref_drops[R - 1] - pref_drops[L]
                wrap_drop = 1 if nums[R - 1] > nums[L] else 0
                
                if internal_drops + wrap_drop > 1:
                    possible = False
                    break
            
            if possible:
                ans += k
                
        return ans