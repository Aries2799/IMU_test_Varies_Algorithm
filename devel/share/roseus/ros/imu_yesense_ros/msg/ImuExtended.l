;; Auto-generated. Do not edit!


(when (boundp 'imu_yesense_ros::ImuExtended)
  (if (not (find-package "IMU_YESENSE_ROS"))
    (make-package "IMU_YESENSE_ROS"))
  (shadow 'ImuExtended (find-package "IMU_YESENSE_ROS")))
(unless (find-package "IMU_YESENSE_ROS::IMUEXTENDED")
  (make-package "IMU_YESENSE_ROS::IMUEXTENDED"))

(in-package "ROS")
;;//! \htmlinclude ImuExtended.msg.html


(defclass imu_yesense_ros::ImuExtended
  :super ros::object
  :slots (_acc_x _acc_y _acc_z _angular_velocity_roll _angular_velocity_pitch _angular_velocity_yaw _angle_roll _angle_pitch _angle_yaw ))

(defmethod imu_yesense_ros::ImuExtended
  (:init
   (&key
    ((:acc_x __acc_x) 0.0)
    ((:acc_y __acc_y) 0.0)
    ((:acc_z __acc_z) 0.0)
    ((:angular_velocity_roll __angular_velocity_roll) 0.0)
    ((:angular_velocity_pitch __angular_velocity_pitch) 0.0)
    ((:angular_velocity_yaw __angular_velocity_yaw) 0.0)
    ((:angle_roll __angle_roll) 0.0)
    ((:angle_pitch __angle_pitch) 0.0)
    ((:angle_yaw __angle_yaw) 0.0)
    )
   (send-super :init)
   (setq _acc_x (float __acc_x))
   (setq _acc_y (float __acc_y))
   (setq _acc_z (float __acc_z))
   (setq _angular_velocity_roll (float __angular_velocity_roll))
   (setq _angular_velocity_pitch (float __angular_velocity_pitch))
   (setq _angular_velocity_yaw (float __angular_velocity_yaw))
   (setq _angle_roll (float __angle_roll))
   (setq _angle_pitch (float __angle_pitch))
   (setq _angle_yaw (float __angle_yaw))
   self)
  (:acc_x
   (&optional __acc_x)
   (if __acc_x (setq _acc_x __acc_x)) _acc_x)
  (:acc_y
   (&optional __acc_y)
   (if __acc_y (setq _acc_y __acc_y)) _acc_y)
  (:acc_z
   (&optional __acc_z)
   (if __acc_z (setq _acc_z __acc_z)) _acc_z)
  (:angular_velocity_roll
   (&optional __angular_velocity_roll)
   (if __angular_velocity_roll (setq _angular_velocity_roll __angular_velocity_roll)) _angular_velocity_roll)
  (:angular_velocity_pitch
   (&optional __angular_velocity_pitch)
   (if __angular_velocity_pitch (setq _angular_velocity_pitch __angular_velocity_pitch)) _angular_velocity_pitch)
  (:angular_velocity_yaw
   (&optional __angular_velocity_yaw)
   (if __angular_velocity_yaw (setq _angular_velocity_yaw __angular_velocity_yaw)) _angular_velocity_yaw)
  (:angle_roll
   (&optional __angle_roll)
   (if __angle_roll (setq _angle_roll __angle_roll)) _angle_roll)
  (:angle_pitch
   (&optional __angle_pitch)
   (if __angle_pitch (setq _angle_pitch __angle_pitch)) _angle_pitch)
  (:angle_yaw
   (&optional __angle_yaw)
   (if __angle_yaw (setq _angle_yaw __angle_yaw)) _angle_yaw)
  (:serialization-length
   ()
   (+
    ;; float64 _acc_x
    8
    ;; float64 _acc_y
    8
    ;; float64 _acc_z
    8
    ;; float64 _angular_velocity_roll
    8
    ;; float64 _angular_velocity_pitch
    8
    ;; float64 _angular_velocity_yaw
    8
    ;; float64 _angle_roll
    8
    ;; float64 _angle_pitch
    8
    ;; float64 _angle_yaw
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _acc_x
       (sys::poke _acc_x (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _acc_y
       (sys::poke _acc_y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _acc_z
       (sys::poke _acc_z (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _angular_velocity_roll
       (sys::poke _angular_velocity_roll (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _angular_velocity_pitch
       (sys::poke _angular_velocity_pitch (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _angular_velocity_yaw
       (sys::poke _angular_velocity_yaw (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _angle_roll
       (sys::poke _angle_roll (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _angle_pitch
       (sys::poke _angle_pitch (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _angle_yaw
       (sys::poke _angle_yaw (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _acc_x
     (setq _acc_x (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _acc_y
     (setq _acc_y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _acc_z
     (setq _acc_z (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _angular_velocity_roll
     (setq _angular_velocity_roll (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _angular_velocity_pitch
     (setq _angular_velocity_pitch (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _angular_velocity_yaw
     (setq _angular_velocity_yaw (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _angle_roll
     (setq _angle_roll (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _angle_pitch
     (setq _angle_pitch (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _angle_yaw
     (setq _angle_yaw (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get imu_yesense_ros::ImuExtended :md5sum-) "2eb288617eb70de805bdc572560b798f")
(setf (get imu_yesense_ros::ImuExtended :datatype-) "imu_yesense_ros/ImuExtended")
(setf (get imu_yesense_ros::ImuExtended :definition-)
      "float64 acc_x
float64 acc_y
float64 acc_z
float64 angular_velocity_roll
float64 angular_velocity_pitch
float64 angular_velocity_yaw
float64 angle_roll
float64 angle_pitch
float64 angle_yaw

")



(provide :imu_yesense_ros/ImuExtended "2eb288617eb70de805bdc572560b798f")


