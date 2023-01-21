(format t "Hello Guys ~%")
(write-line "Whats your name?")

(defvar *name* (read)) ;; global Variable inside asterick signs

(defun hello-you (*n*) ;; Function taking single param
    (format t "Hello ~a ! ~%" *n*)
)

;;;; ~a for values , ~% for new line
;;;; ~10a for extra 10 spaces 

(setq *print-case* :capitalize) ;; Setting output as Capitalized

(hello-you *name*)
