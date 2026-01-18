\## Problem Idea Development



The goal of this problem was to design a range query task that cannot

be solved using prefix sums or simple frequency counting.



Initially, I considered counting distinct elements, but that approach

is very common and well known. I then shifted the focus to counting

positions that belong to duplicated values inside a query range.



This small change makes the problem significantly harder and requires

offline query processing techniques such as Mo’s Algorithm.



