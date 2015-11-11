
class Trie:
    def __init__(self):
        # 0 is the root - denoting empty string
        self._parent = {0 : -1}          # collection of node, parent pair
        # Mapping of the satellite data to their states
        self._words = {0: 0}    # Words stored below a node
        self._total_states = 1
        self._isWord = {0 : False}
        self._transitions = {0: {}}     # stores the adjacency-list of each of the state

    # @params word: word to be stored in the trie
    def addWord(self, word):
    	current_state = 0
    	self._words[0] += 1	# addition of one more word
    	for letter in word[:-1]:
            if letter not in self._transitions[current_state]:
                self._transitions[self._total_states] = {}      # create a new state
                self._words[self._total_states] = 0    # Non-accepting
                self._parent[self._total_states] = current_state
                self._transitions[current_state][letter] = self._total_states
                self._isWord[self._total_states] = self._isWord.get(self._total_states, False)
                self._total_states += 1
            current_state = self._transitions[current_state][letter]
            self._words[current_state] += 1

        if word[-1] not in self._transitions[current_state]:
        	self._transitions[self._total_states] = {}      # create a new state
        	self._words[self._total_states] = 1     # Accepting
        	self._parent[self._total_states] = current_state
        	self._transitions[current_state][word[-1]] = self._total_states
        	self._isWord[self._total_states] = True
        	self._total_states += 1


    def prefix_len(self, word):
        current_state = 0
        counter = 0
        for letter in word:
            if current_state != 0 and self._words[current_state] == 1:
                return counter
            else:
                counter += 1
                current_state = self._transitions[current_state][letter]
        return len(word)



cas = input()
for i in range(1, cas + 1):
    t = Trie()
    min_len = 0
    n = input()
    words = [raw_input() for _ in range(n)]
    for word in words:
        t.addWord(word)
        min_len += t.prefix_len(word)
    print "Case #" + str(i) + ': ' + str(min_len)
