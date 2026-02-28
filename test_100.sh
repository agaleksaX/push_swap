#!/bin/sh
cd "$(dirname "$0")" || exit 1
nums=$(python3 - <<PY
import random
nums = random.sample(range(-10000,10000), 100)
print(' '.join(map(str, nums)))
PY
)
echo "Testing 100 numbers..."
echo "$nums"
mkdir -p /tmp/pushswap_test
./push_swap $nums | tee /tmp/pushswap_test/ops.txt | ./checker $nums
res=$?
ops=$(wc -l < /tmp/pushswap_test/ops.txt)
echo "Result: $res (0=OK), operations: $ops"
exit $res
