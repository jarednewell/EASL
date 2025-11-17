# EASL: Enhanced Append-only Skip List

## Introduction
EASL is independent of the blockchain architecture, unlike other indexing techniques that have addressed a specific data indexing problem associated with a specific blockchain type. Such particular indexing techniques prevent the application to different blockchain types and blockchain use cases. Other techniques only address the data contained in a single block, and therefore, cannot provide a relationship between transactions in different blocks. EASL is able to track the relationship between data in different blocks, thus, facilitating and promoting data provenance. This makes real-time data analysis of the blockchain practical.

### EASL indexing technique - skip list node structure.
![EASL indexing technique - skip list node structure.](https://ars.els-cdn.com/content/image/1-s2.0-S0167739X24005181-gr2.jpg)

## The Node Construction Algorithm
The algorithm and the supporting structure included in this repository is written in C++, all definitions and the implementation of EASL is included in the following article:

https://doi.org/10.1016/j.future.2024.107554

## Reference
If you intend on using EASL and this repository we request you reference using the following:

Harvard
```
Newell, J., ur Rehman, S., Mamun, Q. and Islam, M.Z., 2024.
EASL: Enhanced append-only skip list index for agile block data retrieval on blockchain.
Future Generation Computer Systems, p.107554.
```

APA
```
Newell, J., ur Rehman, S., Mamun, Q., & Islam, M. Z. (2024).
EASL: Enhanced append-only skip list index for agile block data retrieval on blockchain.
Future Generation Computer Systems, 107554.
```

BibTeX
```
@article{newell2024,
  title={{EASL}: Enhanced append-only skip list index for agile block data retrieval on blockchain},
  author={Newell, Jared and ur Rehman, Sabih and Mamun, Quazi and Islam, Md Zahidul},
  journal={Future Generation Computer Systems},
  pages={107554},
  year={2024},
  publisher={Elsevier}
}
```
