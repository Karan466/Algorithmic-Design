\## Solution Explanation



For a given range \[L, R], a position contributes to the echo value

only if its value appears at least twice within the same range.



If a value appears exactly once, its position should not be counted.

Therefore, the answer is computed as:



echo value = (R - L + 1) - (number of values occurring exactly once)



This can be efficiently maintained using Mo’s Algorithm by tracking

frequencies and the count of elements that appear exactly once.



