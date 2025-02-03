# Traffic light system

## Table of Contents:

### 1. Introduction (Giới thiệu đề tài)
- **Goal (Mục tiêu):** Hiện thực ứng dụng biểu diễn hệ thống đèn giao thông tại ngã tư trên board Nucleo-F103RB, dựa trên vi điều khiển STM32, sử dụng nút nhấn & màn hình hiển thị thông tin.
- **Requirement (Yêu cầu):**
	- Hệ thống được mô phỏng trên mạch thật là board Nucleo-F103RB dựa trên vi điều khiển STM32 (STM32F103RB).
	- Sử dụng 2 đèn giao thông có 3 màu RED (đỏ), YELLOW (vàng) và GREEN (xanh) để tượng trưng cho 4 đèn giao thông ở ngã tư.
	- Hiển thị thông tin (mode, status, time, led) trên màn hình LCD 16x2 tượng trưng đèn đếm lùi thời gian trong hệ thống đèn giao thông ở ngã tư.
	- Chế độ điều khiển đèn giao thông có ít nhất 2 chế độ, gồm chế độ tự động & chế độ thủ công (sử dụng nút nhấn).
 ![Image](https://github.com/user-attachments/assets/5bf6e0ec-b995-4126-a0ab-9e3338412bda)

### 2. Implement (Hiện thực hệ thống)
- **Tổng quan hệ thống:**
	- **Chế độ tự động - Mode AUTO:** Mô phỏng trạng thái giao thông được điều khiển tự động theo đèn giao thông tại ngã tư trong thực tế.
	- **Chế độ điều khiển bằng tay - Mode MANUAL:** Mô phỏng trạng thái giao thông tại ngã tư được điều khiển thủ công theo hiệu lệnh của cảnh sát giao thông (CSGT) trong thực tế.
	- **Chế độ điều chỉnh thời gian của đèn - Mode SETTING:** Hiện thực chế độ điều chỉnh thời gian (duration) cho từng màu của đèn 3 màu.
	- **Chuyển chế độ:** Chế độ AUTO chuyển sang chế độ MANUAL (và ngược lại) bằng việc nhấn thả nút nhấn 0, chế độ AUTO chuyển sang chế độ SETTING (và ngược lại) bằng việc nhấn đè nút nhấn 0.
![Image](https://github.com/user-attachments/assets/834d8d29-24a8-454e-9127-b1beb98fea38)

- **Các chế độ cụ thể:**
  - ***Mode 1: AUTO***
![Image](https://github.com/user-attachments/assets/eb583676-1a62-4565-8c23-86273c135cdc)
	- Thời gian hiển thị: thời gian còn lại của đèn đang sáng.
	- Phương tiện lưu thông theo quy tắc của 3 màu đèn trong thời gian (duration) của từng đèn. Sau khi hết thời gian thì chuyển trạng thái (đèn sáng-tắt), hoạt động tuần tự, lặp lại.
	- Quy tắc về thời gian: để vận hành được hệ thống giao thông tại ngã tư thì ta tuân theo quy tắc thời gian đèn ĐỎ = thời gian đèn XANH + thời gian đèn VÀNG.
  - ***Mode 2: MANUAL***
![Image](https://github.com/user-attachments/assets/00e1823a-58d4-4e12-8003-3d8cd869664c)
	- Tín hiệu điều khiển của CSGT: đổi hướng lưu thông, mô phỏng bằng nút nhấn 1.
	- Các hướng lưu thông đang di chuyển (đèn XANH) và dừng lại (đèn ĐỎ) thì giữ nguyên trạng thái cho đến khi có tín hiệu thay đổi theo sự điều khiển của CSGT.
	- Các hướng lưu thông đang đi chậm để chuẩn bị dừng lại (đèn VÀNG) sau khi hết thời gian của đèn VÀNG thì dừng lại (đèn ĐỎ), hướng lưu thông đối diện đang chờ (đèn ĐỎ) có thể di chuyển (đèn XANH). Tiếp tục giữ nguyên trạng thái cho đến khi có tín hiệu thay đổi theo sự điều khiển của CSGT.
	- Thời gian hiển thị: Không điều khiển tự động bằng đèn đếm lùi, mô phỏng bằng việc hiển thị giá trị 0 đối với trạng thái giữ nguyên và giá trị thời gian còn lại đối với trạng thái động đang chuẩn bị giữ nguyên (từ đèn VÀNG sang đèn ĐỎ).
  - ***Mode 3: SETTING***
![Image](https://github.com/user-attachments/assets/78aec071-5f43-4585-86d2-c0572b03fca0)
	- Thay đổi đèn (chuyển sang các mode điều chỉnh giá trị của đèn khác): bằng việc nhấn thả nút nhấn 0.
	- Điều chỉnh giá trị thời gian hoạt động của đèn (quy ước tăng): bằng việc nhấn thả nút nhấn 1, mỗi lần nhấn là tăng 1 đơn vị.
	- Lưu giá trị vừa thay đổi (và chuyển về mode AUTO): bằng việc nhấn đè nút nhấn 0.
	- Nếu như thay đổi giá trị (nhấn nút 1) nhưng không lưu giá trị (nhấn đè nút 0) mà đã chuyển sang điều chỉnh đèn khác (nhấn nút 0) thì giá trị thời gian hoạt động của đèn đó
vẫn như cũ, không bị thay đổi.
  - ***Chức năng các nút nhấn***
![Image](https://github.com/user-attachments/assets/edec7409-93c3-45aa-9d6c-1045c00e2500)

### 3.	Result (Kết quả)
Đây là link video demo: https://youtube.com/shorts/9gGl9BBp63M
