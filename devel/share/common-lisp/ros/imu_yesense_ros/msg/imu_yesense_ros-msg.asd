
(cl:in-package :asdf)

(defsystem "imu_yesense_ros-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "ImuExtended" :depends-on ("_package_ImuExtended"))
    (:file "_package_ImuExtended" :depends-on ("_package"))
  ))