# Djikstra's Algorithm
### Implemented in my favorite language, C 😎
- In uni, we typically hide behind fancy object-oriented features to make life easy.
- Alas, the results of me wanting to brush off my C skills!

## Things to note:
The runtime of my algorithm is $O((|V| + |E|) * log(|V|))$
- The widely used version of Djikstra's has a better performance of $O((|V|log(|V|) + |E|)$
- This comes down to the more popular implementation using a fibonacci heap, while my implementation uses a min-heap