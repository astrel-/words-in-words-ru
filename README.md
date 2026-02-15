# words-in-words-ru



C++ command-line solver for the Russian version of the “Words in Words” game.



Given a set of letters via standard input, the program finds all valid Russian nouns that can be formed from them and outputs results sorted by score (ascending).



---



## Features



- Russian noun dictionary support

- UTF-16-aware text handling

- Length-based scoring

---



## How It Works



1. Loads the dictionary from `data/russian-nouns.txt`

2. Reads input word from `stdin`

3. Checks whether each dictionary word can be formed from the provided letters

4. Computes score based on word length

5. Sorts results by score (ascending)

6. Outputs matching words



---



## Build (Windows / MSVC)



1. Open `words-in-words-ru.sln` in Visual Studio  

2. Select `Release x64`  

3. Build and run  



---



## Usage



Provide letters via standard input:

```

прорубь

```



Example output:



```

убор: 4

упор: 4

поруб: 5

рупор: 5

порубь: 6

проруб: 6

прорубь: 7

```



---



## Limitations



- Does not currently normalize `е` / `ё`

- Windows/MSVC build only



---



## TODO



- [ ] Add command-line arguments

- [ ] Introduce CMake build for cross-platform support







