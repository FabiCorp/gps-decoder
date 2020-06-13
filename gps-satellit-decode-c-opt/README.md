# Optimizations

- loop unroll
- https://www.rapidtables.com/code/linux/gcc/gcc-o.html -Ofast
- inline function for correlation value -> improve time performance (by eliminating call overhead)
  - at the cost of worsening space usage (due to duplicating the function body). 
  