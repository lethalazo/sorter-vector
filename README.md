# sorter-vector
A sorter in C++ that utilizes the power of vectors.

A Not so elegant C++ sorting program that I developed, during a 'eureka' moment to make better use of vectors, in 30 mins, in the middle of the night.
(took me another 30mins to put in the comments)

The algorithm basically is: if the element is bigger or equal, push it back in the vector.
Else go to the checker function, which does this:
**Base Cases** 
1. If the element being compared is the first element in the vector and the current element is smaller than it, insert it before the vector element.
2. If it is bigger than the element in the vector, insert it after it.
(else,) keep doing the above over again with all the other elements in the vector by recurring the checker function.