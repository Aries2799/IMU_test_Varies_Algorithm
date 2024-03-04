
(cl:in-package :asdf)

(defsystem "imu_yesense_ros-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "ImuExtended" :depends-on ("_package_ImuExtended"))
    (:file "_package_ImuExtended" :depends-on ("_package"))
    (:file "attitude" :depends-on ("_package_attitude"))
    (:file "_package_attitude" :depends-on ("_package"))
  ))