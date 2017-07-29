

## Getting Started
Hello friends…! IToday we will talk about the Trie Tree Implementation. When I first heard about the Trie data structure I was fascinated by the level of low complexity and high efficiency for a word to be looked up amongst a large collection of words.  

So, first of all let me show you it’s impact while searching for a word using a real world problem. The latest version of Oxford dictionary contains an entry of near to 1,70,000 words in current use. To use this dictionary, searching for a word from this collection should be very fast. Using any data structure other than tries would be a very bad idea as searching would give a time complexity proportional to the number of words. Also, if you think of using direct hashing to find a word, it would require a lot of memory to store this much amount of words. 

So, how can tries help us on improving both the time and space complexities? Average length of a word in English dictionary is 5. Tries search for just five nodes on average to find a word from the dictionary. Therefore, practically tries search time is O(5) which can be taken as constant and as you can see, that is a dramatic improvement. Also, it does not stores each word differently like maps and stores same prefix from different words only once which results in decreasing the space complexity. As a result of my research about the topic, I ended up implementing it and enjoyed making it work.







## What is trie?
Trie is an efficient information retrieval data structure. Trie Trees are used to search for all occurrences of a word in a given text very quickly. To be precise, if the length of the word is “L“, the trie tree searches for all occurrences of this data structure in O(L) time, which is very fast in comparison to other algorithms.

The Trie Tree is a very straight forward data structure. It is a simple tree where the nodes have an alphabet associated with them. And the way these nodes are arranged is the best part of the Trie Tree. To get an idea take a close look at the sketch below :
 
![image](https://user-images.githubusercontent.com/29864394/28640098-3b2cdf72-7268-11e7-973a-f51615ce296e.png)  
**Figure 1. Structure of Trie Tree**

The arrows in the sketch above indicate how to traverse the trie tree in order to tell if a word exists or not. In the worst case, one would have to travel the height of the tree which would be the length of the longest word in the whole text.





## What are it's Applications
Trie or prefix tree is a tree data structure, which is used for retrieval of a key in a dataset of strings. There are various applications of this very efficient data structure such as:
#### 1. Autocomplete
 
 ![image](https://user-images.githubusercontent.com/29864394/28640645-0064d104-726a-11e7-8a13-9b51bc15f9aa.png)  
**Figure 2. Google Suggest in action.**  
                
* Auto-complete functionality is used widely over the internet and mobile apps. A lot of websites and apps try to complete your input as soon as you start typing.
* Since a trie is a tree-like data structure in which each node contains an array of pointers, one pointer for each character in the alphabet. 
* Implementing auto complete using a trie is easy. 
* We simply trace pointers to get to a node that represents the string the user entered. By exploring the trie from that node down, we can enumerate all strings that complete user’s input.








#### 2. Spell checker
 
 
![image](https://user-images.githubusercontent.com/29864394/28640705-2fee4c70-726a-11e7-8acb-7017ae51922c.png)  
**Figure 3. A spell checker used in word processor.**
     
* Spell checkers are ubiquitous. Word processors have spell checkers, as do browser-based e-mail clients. They all work the same way: a dictionary is stored in some data structure, then each word of input is submitted to a search in the data structure, and those that fail are flagged as spelling errors.
* Starting from the root node, you can check if a word exists in the trie easily by following pointers corresponding to the letters in the target word.



#### 3. T9 predictive text
 
 
![image](https://user-images.githubusercontent.com/29864394/28640741-4c328ed2-726a-11e7-8cba-b5b8e2a75da3.png)  
**Figure 4. T9 which stands for Text on 9 keys, was used on phones to input texts during the late 1990s.**

* T9 is a technology used on many mobile phones to make typing text messages easier.
* The idea is simple - each number of the phone's keypad corresponds to 3-4 letters of the alphabet. 
* It can be implemented in several ways, one of them is Trie. The route is represented by the digits and the nodes point to collection of words.
* T9 works by filtering the possibilities down sequentially starting with the first possible letters.
* For  example, If we type '4663' we get 'good' when we press down button we get 'gone' then 'home' etc..


There are several other data structures, like balanced trees and hash tables, which give us the possibility to search for a word in a dataset of strings. Then why do we need trie? Although hash table has O(1) time complexity for looking for a key, it is not efficient in the following operations :
* Finding all keys with a common prefix.
* Enumerating a dataset of strings in lexicographical order.

Another reason why trie outperforms hash table, is that as hash table increases in size, there are lots of hash collisions and the search time complexity could deteriorate to O(n), where n is the number of keys inserted. Trie could use less space compared to Hash Table when storing many keys with the same prefix. In this case using trie has only O(m) time complexity, where m is the key length. Searching for a key in a balanced tree costs O(m*logn) time complexity.



















































































































































































