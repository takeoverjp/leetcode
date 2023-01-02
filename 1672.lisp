(defun sum (l)
  (if l
    (+ (car l) (sum (cdr l)))
    0))
(defun maximum-wealth (accounts)
  (if accounts
    (let ((s (sum (car accounts))))
      (max s (maximum-wealth (cdr accounts))))
    0))

(ql:quickload "fiveam")
(5am:test test-1 (5am:is (= (maximum-wealth '((1 2 3) (3 2 1))) 6)))
(5am:test test-2 (5am:is (= (maximum-wealth '((1 5) (7 3) (3 5))) 10)))
(5am:test test-3 (5am:is (= (maximum-wealth '((2 8 7) (7 1 3) (1 9 5))) 17)))
(5am:run!)
