(defun number-of-matches (n)
  (if (= n 1) 0 (+ (floor n 2) (number-of-matches (+ (floor n 2) (logand n 1))))))

(ql:quickload "fiveam")
(5am:test test-1 (5am:is (= (number-of-matches 7) 6)))
(5am:test test-2 (5am:is (= (number-of-matches 14) 13)))
(5am:run!)
