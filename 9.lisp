(defun is-palindrome (l)
  (equal l (reverse l)))

(defun palindrome-number (num)
  (if (< num 0) nil
    (let ((nums ())
        (d (mod num 10)))
      (loop for i from (mod num 10)
        while (> num 0) do
          (setq nums (cons d nums))
          (setq num (floor num 10))
          (setq d (mod num 10)))
    ;;   (format t "nums~A~%" nums)
      (is-palindrome nums))
  ))

(ql:quickload "fiveam")
;; (trace palindrome-number)
(5am:test test-1 (5am:is (eq t (palindrome-number 121))))
(5am:test test-2 (5am:is (eq nil (palindrome-number -121))))
(5am:test test-3 (5am:is (eq nil (palindrome-number 10))))
(5am:run!)
