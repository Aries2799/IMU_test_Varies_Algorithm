;; Auto-generated. Do not edit!


(when (boundp 'imu_yesense_ros::ImuExtended)
  (if (not (find-package "IMU_YESENSE_ROS"))
    (make-package "IMU_YESENSE_ROS"))
  (shadow 'ImuExtended (find-package "IMU_YESENSE_ROS")))
(unless (find-package "IMU_YESENSE_ROS::IMUEXTENDED")
  (make-package "IMU_YESENSE_ROS::IMUEXTENDED"))

(in-package "ROS")
;;//! \htmlinclude ImuExtended.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass imu_yesense_ros::ImuExtended
  :super ros::object
  :slots (_header _acc_x _acc_y _acc_z _angular_velocity_x _angular_velocity_y _angular_velocity_z _magnetic_x _magnetic_y _magnetic_z ))

(defmethod imu_yesense_ros::ImuExtended
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:acc_x __acc_x) 0.0)
    ((:acc_y __acc_y) 0.0)
    ((:acc_z __acc_z) 0.0)
    ((:angular_velocity_x __angular_velocity_x) 0.0)
    ((:angular_velocity_y __angular_velocity_y) 0.0)
    ((:angular_velocity_z __angular_velocity_z) 0.0)
    ((:magnetic_x __magnetic_x) 0.0)
    ((:magnetic_y __magnetic_y) 0.0)
    ((:magnetic_z __magnetic_z) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _acc_x (float __acc_x))
   (setq _acc_y (float __acc_y))
   (setq _acc_z (float __acc_z))
   (setq _angular_velocity_x (float __angular_velocity_x))
   (setq _angular_velocity_y (float __angular_velocity_y))
   (setq _angular_velocity_z (float __angular_velocity_z))
   (setq _magnetic_x (float __magnetic_x))
   (setq _magnetic_y (float __magnetic_y))
   (setq _magnetic_z (float __magnetic_z))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:acc_x
   (&optional __acc_x)
   (if __acc_x (setq _acc_x __acc_x)) _acc_x)
  (:acc_y
   (&optional __acc_y)
   (if __acc_y (setq _acc_y __acc_y)) _acc_y)
  (:acc_z
   (&optional __acc_z)
   (if __acc_z (setq _acc_z __acc_z)) _acc_z)
  (:angular_velocity_x
   (&optional __angular_velocity_x)
   (if __angular_velocity_x (setq _angular_velocity_x __angular_velocity_x)) _angular_velocity_x)
  (:angular_velocity_y
   (&optional __angular_velocity_y)
   (if __angular_velocity_y (setq _angular_velocity_y __angular_velocity_y)) _angular_velocity_y)
  (:angular_velocity_z
   (&optional __angular_velocity_z)
   (if __angular_velocity_z (setq _angular_velocity_z __angular_velocity_z)) _angular_velocity_z)
  (:magnetic_x
   (&optional __magnetic_x)
   (if __magnetic_x (setq _magnetic_x __magnetic_x)) _magnetic_x)
  (:magnetic_y
   (&optional __magnetic_y)
   (if __magnetic_y (setq _magnetic_y __magnetic_y)) _magnetic_y)
  (:magnetic_z
   (&optional __magnetic_z)
   (if __magnetic_z (setq _magnetic_z __magnetic_z)) _magnetic_z)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; float64 _acc_x
    8
    ;; float64 _acc_y
    8
    ;; float64 _acc_z
    8
    ;; float64 _angular_velocity_x
    8
    ;; float64 _angular_velocity_y
    8
    ;; float64 _angular_velocity_z
    8
    ;; float64 _magnetic_x
    8
    ;; float64 _magnetic_y
    8
    ;; float64 _magnetic_z
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; float64 _acc_x
       (sys::poke _acc_x (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _acc_y
       (sys::poke _acc_y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _acc_z
       (sys::poke _acc_z (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _angular_velocity_x
       (sys::poke _angular_velocity_x (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _angular_velocity_y
       (sys::poke _angular_velocity_y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _angular_velocity_z
       (sys::poke _angular_velocity_z (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _magnetic_x
       (sys::poke _magnetic_x (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _magnetic_y
       (sys::poke _magnetic_y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _magnetic_z
       (sys::poke _magnetic_z (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; float64 _acc_x
     (setq _acc_x (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _acc_y
     (setq _acc_y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _acc_z
     (setq _acc_z (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _angular_velocity_x
     (setq _angular_velocity_x (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _angular_velocity_y
     (setq _angular_velocity_y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _angular_velocity_z
     (setq _angular_velocity_z (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _magnetic_x
     (setq _magnetic_x (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _magnetic_y
     (setq _magnetic_y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _magnetic_z
     (setq _magnetic_z (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get imu_yesense_ros::ImuExtended :md5sum-) "d610238899c9b65ff1d2c524fd6e233f")
(setf (get imu_yesense_ros::ImuExtended :datatype-) "imu_yesense_ros/ImuExtended")
(setf (get imu_yesense_ros::ImuExtended :definition-)
      "std_msgs/Header header
float64 acc_x
float64 acc_y
float64 acc_z
float64 angular_velocity_x
float64 angular_velocity_y
float64 angular_velocity_z
float64 magnetic_x
float64 magnetic_y
float64 magnetic_z

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id

")



(provide :imu_yesense_ros/ImuExtended "d610238899c9b65ff1d2c524fd6e233f")


