# Disjoint Set (Union-Find)

## Example

```
Initialize
{ 0 } { 1 } { 2 } { 3 } { 4 } { 5 } { 6 } { 7 } { 8 } { 9 }

Union 2 and 5
{ 0 } { 1 } { 2, 5 } { 3 } { 4 } { 6 } { 7 } { 8 } { 9 }

Union 5 and 7
{ 0 } { 1 } { 2, 5, 7 } { 3 } { 4 } { 6 } { 8 } { 9 }

Union 5 and 0
{ 1 } { 0, 2, 5, 7 } { 3 } { 4 } { 6 } { 8 } { 9 }

Union 4 and 8
{ 1 } { 0, 2, 5, 7 } { 3 } { 4, 8 } { 6 } { 9 }

Union 9 and 4
{ 1 } { 0, 2, 5, 7 } { 3 } { 4, 8, 9 } { 6 }

Union 1 and 6
{ 1, 6 } { 0, 2, 5, 7 } { 3 } { 4, 8, 9 }

Union 8 and 0
{ 1, 6 } { 0, 2, 4, 5, 7, 8, 9 } { 3 }
```

## Reference

* https://en.wikipedia.org/wiki/Disjoint-set_data_structure
* https://www.geeksforgeeks.org/disjoint-set-data-structures
* https://kks227.blog.me/220791837179 (Korean)
