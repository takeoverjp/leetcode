(defun list-to-string (lst)
  (format nil "~{~A~}" lst))

(defun array-strings-are-equal (word1 word2)
  (equal (list-to-string word1) (list-to-string word2)))

(assert (array-strings-are-equal '("ab" "c") '("a" "bc")))
(assert (not (array-strings-are-equal '("a" "cb") '("ab" "c"))))
(assert (array-strings-are-equal '("abc" "d" "defg") '("abcddefg")))
