;; [14] Longest Common Prefix

(defun longest-common-prefix (strs)
  (if (= (length strs) 0)
    ""
    (let ((ans (nth 0 strs)) (idx 0) (next ""))
      (loop for str in strs do
        (setf idx 0)
        (setf next "")
        (loop for c across ans do
          (if (and (< idx (length str)) (eq c (char str idx))) (setf next (format nil "~A~A" next c))
            (return))
          (format t "str=~A c=~A str[idx]=~A next=~A ans=~A~%" str c (char str idx) next ans)
          (incf idx)))
        (setf ans next)
       ans)))

(ql:quickload "fiveam")
;; (trace longest-common-prefix)
(5am:test test-1 (5am:is (equal "" (longest-common-prefix ()))))
(5am:test test-2 (5am:is (equal "fl" (longest-common-prefix '("flower" "flow" "flight")))))
(5am:test test-3 (5am:is (equal "" (longest-common-prefix '("dog" "racecar" "car")))))
(5am:test test-4 (5am:is (equal "a" (longest-common-prefix '("a" "ab")))))
(5am:test test-5 (5am:is (equal "a" (longest-common-prefix '("ab" "a")))))
(5am:run!)
