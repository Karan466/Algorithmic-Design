# Echo Segments

You are given an integer array `A` of length `N`.

For any subarray `[L, R]`, define its **echo value** as the number of indices
`i` such that `L ≤ i ≤ R` and the value `A[i]` occurs **at least twice**
inside the same subarray `[L, R]`.

### Example
- Subarray `[2, 5, 2]` has echo value `3`
- Subarray `[1, 2, 3]` has echo value `0`

---

## Input Format

- First line contains two integers `N` and `Q`
- Second line contains `N` integers `A1, A2, ...,
