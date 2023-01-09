(defun two-sum (nums target)
  (let ((len (length nums)))
    (loop named outer for i below len do 
      (loop for j from (+ i 1) to (- len 1) do
        ;; (format t "nums[~A]=~A nums[~A]=~A~%" i (nth i nums) j (nth j nums))
        (if (= (+ (nth i nums) (nth j nums)) target) (return-from outer (list i j)))))
    ))

(ql:quickload "fiveam")
;; (trace two-sum)
(5am:test test-1 (5am:is (equal (two-sum '(2 7 11 15) 9) '(0 1))))
(5am:test test-2 (5am:is (equal (two-sum '(3 2 4) 6) '(1 2))))
(5am:test test-3 (5am:is (equal (two-sum '(3 3) 6) '(0 1))))
(5am:run!)
