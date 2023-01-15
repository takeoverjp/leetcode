(defun trailing-zeroes (n)
  (let ((ret 0))
    (loop while (> n 0) do
      (setf n (floor n 5))
      (setf ret (+ ret n)))
      ret))

(ql:quickload "fiveam")
(5am:test test-1 (5am:is (= (trailing-zeroes 3) 0)))
(5am:test test-2 (5am:is (= (trailing-zeroes 5) 1)))
(5am:test test-3 (5am:is (= (trailing-zeroes 0) 0)))
(5am:run!)
