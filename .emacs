; ---- language-env DON'T MODIFY THIS LINE!
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; ���ܸ�ɽ��������
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;; ����Ķ������ܸ�����ꡥ
;;; ����������������ꤹ��ȥǥե���Ȥ�EUC �ˤʤ�Τ���ա�
;;; ��������θ�ˡ�ʸ�������ɤ����ꤹ�롥
(set-language-environment "Japanese")

;;; ʸ�������ɤ����ꡥ
(set-terminal-coding-system 'utf-8-unix)
(set-keyboard-coding-system 'utf-8-unix)
(set-buffer-file-coding-system 'utf-8-unix)
(setq default-buffer-file-coding-system 'utf-8-unix)
(prefer-coding-system 'utf-8-unix)
(set-default-coding-systems 'utf-8-unix)
(setq file-name-coding-system 'utf-8-unix)


; ���ܸ� grep
(if (file-exists-p "/usr/bin/lgrep")
    (setq grep-command "lgrep -n ")
)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; ������
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Delete�����ǥ���������֤�ʸ�����ä���褦�ˤ���
(global-set-key [delete] 'delete-char)

(load (expand-file-name "~/.emacs.custom") nil t nil)

; ---- language-env end DON'T MODIFY THIS LINE!
