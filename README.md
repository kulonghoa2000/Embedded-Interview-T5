<details>
  <summary>*BitWise Operarion (Thao tác bit)</summary>

- AND (Biểu thức AND): Ký hiệu: `&`.
  | A | B | A & B |
  |---|---|:---:|
  |0|0| 0|
  |0|1| 0|
  |1|0| 0|
  |1|1| 1|
  ```c
  unsigned int a = 5;  // 0101
  unsigned int b = 3;  // 0011
  unsigned int result = a & b;  // 0001
  ```
- OR (Biểu thức OR): Ký hiệu: `|`.
  | A | B | A \| B |
  |---|---|:---:|
  |0|0| 0|
  |0|1| 1|
  |1|0| 1|
  |1|1| 1|
  ```c
  unsigned int a = 5;  // 0101
  unsigned int b = 3;  // 0011
  unsigned int result = a | b;  // 0111
  ```
- XOR (Biểu thức XOR): Ký hiệu: `^`.
  | A | B | A ^ B |
  |---|---|:---:|
  |0|0| 0|
  |0|1| 1|
  |1|0| 1|
  |1|1| 0|
  ```c
  unsigned int a = 5;  // 0101
  unsigned int b = 3;  // 0011
  unsigned int result = a ^ b;  // 0110
  ```
- NOT (Biểu thức NOT): Ký hiệu: `~`, thực hiện phép NOT bit, đảo ngược tất cả các bit của số.
  | A | ~ A |
  |--|:---:|
  |0| 1|
  |1| 0|
  ```c
  unsigned int a = 5;  // 0101
  unsigned int result = ~a;  // 1010 (đảo ngược các bit)
  ```
- Left Shift (Dịch trái): Ký hiệu: `<<`.
  ```c
  unsigned int a = 5;  // 0101
  unsigned int result = a << 2;  // 010100 (dịch trái 2 vị trí)
  ```
- Right Shift (Dịch phải): Ký hiệu: `>>`.
  ```c
  unsigned int a = 5;  // 0101
  unsigned int result = a >> 2;  // 0001 (dịch phải 2 vị trí)
  ```
- Left Shift và Assign (Dịch trái và gán): Ký hiệu: `<<=`, dịch trái các bit của số `a` đi `b` vị trí và gán lại giá trị cho `a`.
  `a <<= b;`
- Right Shift và Assign (Dịch phải và gán): Ký hiệu: `>>=`, dịch phải các bit của số `a` đi `b` vị trí và gán lại giá trị cho `a`.
  `a >>= b;`
- Bitwise AND và Assign (AND bit và gán): Ký hiệu: `&=`, thực hiện phép AND bit trên từng cặp bit của hai số và gán lại giá trị cho `a`.
  `a &= b;`
- Bitwise OR và Assign (OR bit và gán): Ký hiệu: `|=`, thực hiện phép OR bit trên từng cặp bit của hai số và gán lại giá trị cho `a`.
  `a |= b;`
- Bitwise XOR và Assign (XOR bit và gán): Ký hiệu: `^=`, thực hiện phép XOR bit trên từng cặp bit của hai số và gán lại giá trị cho `a`.
`a ^= b;`
</details>
 
 ##

### Ngôn ngữ C

<details>
  <summary>*Quá trình biên dịch</summary>
	
Quy trình dịch là quá trình chuyển đổi từ ngôn ngữ bậc cao (NNBC) (C/C++, Pascal, Java, C#…) sang ngôn ngữ đích (ngôn ngữ máy) để máy tính có thể hiểu và thực thi. Ngôn ngữ lập trình C là một ngôn ngữ dạng biên dịch. Chương trình được viết bằng C muốn chạy được trên máy tính phải trải qua một quá trình biên dịch để chuyển đổi từ dạng mã nguồn sang chương trình dạng mã thực thi.
	
### Quá trình biên dịch bao gồm 4 giai đoạn:
	
- **_Pre-processor (Giai đoạn tiền xử lý):_** Nhận mã nguồn và xóa bỏ các dòng comments, xử lý các chỉ thị tiền xử lý có bắt đầu bằng kí hiệu `#`. Như `#include` (thay thế mã chương trình của một tệp tiêu để vào mã nguồn cần dịch), `#define` (thay thế bằng giá trị cụ thể tại mỗi nơi sử dụng trong chương trình).
	-  Sau khi qua quá trình tiền xử lý thì file code lúc này sẽ có dạng `.i`.
	-  Dùng lệnh `gcc -E filename.c -o filename.i` hoặc `gcc -E filename.c` để xem code sau khi qua quá trình preprocessor.
- **_Compiler (Giai đoạn dịch NNBC sang ngôn ngữ Assembly):_** Kiểm tra các kiểu dữ liệu có lỗi hay không, phân tích cú pháp (syntax) của mã nguồn NNBC và tối ưu code.
	-  Quá trình này sẽ biên dịch từ code `.i` sang ngôn ngữ assembly `.s`.
	-  Dùng lệnh `gcc -S -o filename.s filename.c` để có thể xem code sau quá tình compiler.
- **_Assembler (Giai đoạn dịch ngôn ngữ Assembly sang ngôn ngữ máy):_** Biên dịch ngôn ngữ Assembly sang ngôn ngữ máy (0 và 1). Và tạo ra tệp tin Object `.o` or `.obj`.
	-  Dùng lệnh `gcc -c filename.c -o filename.o` để tạo ra file ".o" và dùng lệnh `objdump -d -Mintel filename.o` để xem code.
- **_Linker (Giải đoạn liên kết):_** Trong giai đoạn này mã máy của một chương trình `.o` dịch từ nhiều nguồn (file .c hoặc file thư viện .lib) được liên kết lại với nhau để tạo thành chương trình đích nhất. Mã máy của các hàm thư viện gọi trong chương trình cũng được đưa vào chương trình cuối trong giai đoạn này. Chính vì vậy mà các lỗi liên quan đến việc gọi hàm hay sử dụng biến tổng thể mà không tồn tại sẽ bị phát hiện. Kể cả lỗi viết chương trình chính không có hàm main() cũng được phát hiện trong liên kết.
	- File sau khi được gộp lại thì sẽ có đuôi mở rộng Executable `.exe`, còn trên Linux và MacOs thì có thể có đuối theo chỉ định hoặc không có đuôi mở rộng.

- Để chạy file code C trên `terminal` dùng lệnh `gcc -o filename filename.c` đẻ tạo ra tệp thực thi, sau đó dùng lệnh `./filename` để chạy tệp thực thi đó.

### Boot Mode

- Cấp nguồn:
  - Khi cấp nguồn cho vi điều khiển, nó sẽ bắt đầu quá trình khởi động.
  - Lúc này các thanh ghi và bộ nhớ của vi điều khiển sẽ có giá trị không xác định.
- Tạo Stack Pointer(SP):
  - Stack Pointer(SP) là một thanh ghi đặc biệt để quản lý ngăn xếp(stack).
  - Giá trị ban đầu của SP thường được thiết lập tại địa chỉ nhất định trong bộ nhớ.
  - Quá trình thiết lập SP có thể thực hiện thông qua việc gán giá trị một địa chỉ cố định vào thanh ghi SP.
- Tạo Program Counter(PC):
  - Là một thanh ghi đặt biệt dùng để lưu địa chỉ của lệnh hiện tại được thực thi.
  - Giá trị ban đầu của PC thường được thiết lập là địa chỉ bắt đầu của chương trình
  - Quá trình thiệt lập PC thực hiện thông qua việc gán giá trị địa chỉ bắt đầu của chương trình vào thanh ghi PC
- Khởi động chương trình:
  - Sau khi SP và PC được khởi tạo thì chương trình chính bắt đầu khởi động
  - Vi điều khiển sẽ đọc từng câu lệnh và thực thi nó.
  - Nó sẽ thực hiện các lệnh tiếp theo bằng cách tăng giá trị của PC để trỏ đế địa chỉ lệnh tiếp theo
  - Bước nhảy của địa chỉ tùy thuộc vào vi điều khiển (Ví dụ: vđk 8bit thì mỗi lần nhảy thì PC sẽ trỏ tới địa chỉ lên 1byte, tương tự 16bit sẽ là 2 bytes)
  - Trong quá trình chạy, nếu gặp lệnh gọi hàm con thì VĐK sẽ tạo ra một ngăn xếp mới để lưu trữ các biến cục bộ và thông tin của hàm đó.
    - Lúc này, giá trị của SP sẽ lưu lại địa chỉ của câu lệnh hiện tại và giá trị của PC sẽ trỏ tới địa chỉ bắt đầu của hàm con đó và thực thi .
    - Sau khi chạy xong trả về kết quả. Thì ngăn xếp đó sẽ được giải phóng, PC sẽ được gán thành địa chỉ của SP trước đó và tiếp tục thực hiện chương trình.
- **_Ví dụ:_** Chương trình trên VĐK 32bits và địa chỉ của hàm ham() là 0x0000ff00.
  ```C
  #include<stdio.h>
  void ham() {
    	int a = 5;
  }
  int main() {
    	int b = ham();
    	printf("%d", b);
  }
  ```
  - Địa chỉ 0x00000000: Khởi động chương trình.
  - Địa chỉ 0x00000004: Khởi tạo SP với giá trị không xác định.
  - Địa chỉ 0x00000008: Khởi tạo PC với địa chỉ bắt đầu của hàm main(), và PC có giá trị là 0x00000008. SP không thay đổi.
    - Địa chỉ 0x0000000C: PC trỏ tới lệnh trong hàm main() và có địa chỉ là 0x0000000C. SP không thay đổi.
    - Địa chỉ 0x00000010: PC trỏ tới lệnh gọi hàm ham(). PC có địa chỉ là 0x00000010, và SP được gán địa chỉ là 0x00000010 để sau khi chạy xong hàm ham(), PC có thể lấy địa chỉ của SP để chạy tiếp chương trình.
    - Địa chỉ 0x0000FF00: PC trỏ tới địa chỉ bắt đầu của hàm ham(), và PC có địa chỉ là 0x0000FF00. SP vẫn giữ nguyên giá trị là 0x00000010.
    - Địa chỉ 0x0000FF04: PC tiếp tục nhảy thêm 4 byte đối với địa chỉ trước đó để thực hiện lệnh int a = 5, địa chỉ PC lúc này là 0x0000FF04. SP vẫn giữ nguyên giá trị là 0x00000010. Sau khi chạy xong hàm, PC sẽ quay trở lại địa chỉ của SP, tức là 0x00000010.
    - Địa chỉ 0x00000014: PC trỏ tới lệnh printf("%d", b);. Lúc này, địa chỉ PC sẽ là 0x00000014, và SP vẫn giữ nguyên giá trị là 0x00000010.

</details>

<details>
  <summary>*Phân vùng bộ nhớ trên RAM, cấp phát bộ nhớ động</summary>
	
<h3>Phân vùng bộ nhớ trên RAM, cấp phát bộ nhớ động</h3>

|          Stack          |
| :---------------------: |
|            ↓            |
|            ↑            |
|          Heap           |
| Bss(Uninitialized data) |
| Data(Initialized data)  |
|          Text           |

- **_Text:_** Quyền truy cập chỉ có thể Read
  - Chứa khai báo các hằng số(.rodata)
  - Nó chưa lệnh thực thi nên tránh sửa đổi instruction
- **_Data:_** Quyền truy cập Read-Write
  - Chứa biến toàn cục hoặc biến static: Có giá trị khởi tạo khác 0
  - Được giải phóng khi kết thúc chương trình
- **_Bss:_** Quyền truy cập Read-Write
  - Chứa biến toàn cục hoặc các biến static: Có giá trị khởi tạo bằng 0 hoặc không khởi tạo
  - Được giải phóng khi kết thúc chương trình
- **_Stack:_** Quyền truy cập là Read-Write.
  - Được sử dụng cấp phát cho biến local, input parameter của hàm,...
  - Sẽ được giải phóng khi ra khỏi block code/hàm
- **_Heap:_** Quyền truy cập là Read-Write. - Được sử dụng để cấp phát bộ nhớ động như: Malloc, Calloc,... - Sẽ được giải phóng khi gọi hàm free,... ### So sánh Stack và Heap? - Bộ nhớ: Bộ nhớ Heap và bộ nhớ Stack bản chất đều cùng là vùng nhớ được tạo ra và lưu trữ trong RAM khi chương trình được thực thi. - Stack được dùng để lưu trữ các biến cục bộ trong hàm, tham số truyền vào... Truy cập vào bộ nhớ này rất nhanh và được thực thi khi chương trình được biên dịch. - Heap được dùng để lưu trữ vùng nhớ cho những biến con trỏ được cấp phát động bởi các hàm malloc - calloc - realloc (trong C) - Kích thước vùng nhớ: - Stack: kích thước của bộ nhớ Stack là cố định, tùy thuộc vào từng hệ điều hành, ví dụ hệ điều hành Windows là 1 MB, hệ điều hành Linux là 8 MB (lưu ý là con số có thể khác tùy thuộc vào kiến trúc hệ điều hành của bạn). - Heap: kích thước của bộ nhớ Heap là không cố định, có thể tăng giảm do đó đáp ứng được nhu cầu lưu trữ dữ liệu của chương trình. - Đặc điểm vùng nhớ - Stack: vùng nhớ Stack được quản lý bởi hệ điều hành, dữ liệu được lưu trong Stack sẽ tự động hủy khi hàm thực hiện xong công việc của mình. - Heap: Vùng nhớ Heap được quản lý bởi lập trình viên (trong C hoặc C++), dữ liệu trong Heap sẽ không bị hủy khi hàm thực hiện xong, điều đó có nghĩa bạn phải tự tay hủy vùng nhớ bằng câu lệnh free (trong C), và delete hoặc delete [] (trong C++), nếu không sẽ xảy ra hiện tượng rò rỉ bộ nhớ. ### Lưu ý: - Việc tự động dọn vùng nhớ còn tùy thuộc vào trình biên dịch trung gian. - Vấn đề lỗi xảy ra đối với vùng nhớ Stack: Bởi vì bộ nhớ Stack cố định nên nếu chương trình bạn sử dụng quá nhiều bộ nhớ vượt quá khả năng lưu trữ của Stack chắc chắn sẽ xảy ra tình trạng tràn bộ nhớ Stack (Stack overflow), các trường hợp xảy ra như bạn khởi tạo quá nhiều biến cục bộ, hàm đệ quy vô hạn,.. - Ví dụ về tràn bộ nhớ stack với hàm đệ quy vô hạn:
`C
		int foo(int x){
			printf("De quy khong gioi han\n");
			return foo(x);
		}
		` - Vấn đề lỗi xảy ra đối với vùng nhớ Heap: Nếu bạn liên tục cấp phát vùng nhớ mà không giải phóng thì sẽ bị lỗi tràn vùng nhớ Heap (Heap overflow). Nếu bạn khởi tạo một vùng nhớ quá lớn mà vùng nhớ Heap không thể lưu trữ một lần được sẽ bị lỗi khởi tạo vùng nhớ Heap thất bại. - Ví dụ trường hợp khởi tạo vùng nhớ Heap quá lớn:
`C 
		int *A = (int *)malloc(18446744073709551615); 
		` ### Các cách sử dụng malloc, calloc, realloc, free: - **_Malloc:_** Cấp phát bộ nhớ động chưa có giá trị khởi tạo cho mỗi phần tử, trả về con trỏ NULL khi cấp phát thành công
`C 
	void* malloc(size_t size);
	` - **_Calloc:_** Cấp phát bộ nhớ động có giá trị khởi tạo ban đầu của mỗi phần tử đều là 0, trả về con trỏ NULL khi cấp phát thành công
`C
	void* calloc(size_t num, size_t size);
	` - **_Realloc:_** Thay đổi kích thước bộ nhớ của bộ nhớ đã được cấp phát trước đó của Malloc và Calloc, trả về con trỏ NULL khi thay đổi thành công
`C
	void* realloc(void* ptr, size_t size);
	` - **_Free:_** Giải phóng bộ nhớ đã được cấp phát bằng Malloc, Calloc, Realloc sau khi sử dụng xong, không có trả về
`C
	void free(void* ptr);
	`
</details>

<details>
  <summary>*Các biến trong C</summary>
	
- Biến số nguyên (Integer Variables): Lưu trữ giá trị số nguyên không có phần thập phân.
	`int age = 25;`
- Biến số thực (Floating-point Variables): Lưu trữ giá trị số thực có phần thập phân.
	`float pi = 3.14;`
- Biến dấu chấm động (Floating-point Variables): Lưu trữ giá trị số thực có độ chính xác cao hơn float.
    `double pi = 3.14159;`
- Biến dài (Long Variables): Lưu trữ giá trị số nguyên có phạm vi mở rộng so với int.
    `long population = 1000000;`
- Biến ngắn (Short Variables): Lưu trữ giá trị số nguyên có phạm vi nhỏ hơn so với int.
    `short temperature = -10;`
- Biến ký tự (Character Variables): Lưu trữ một ký tự.
	`char grade = 'A';`
- Biến chuỗi ký tự (String Variables): Lưu trữ một chuỗi các ký tự.
	`char name[] = "John";`
- Biến boolean (Boolean Variables): Lưu trữ giá trị đúng (1) hoặc sai (0).
	`int isTrue = 1;`
- Con trỏ (Pointer Variables): Lưu trữ địa chỉ của một biến hoặc vùng nhớ.
	`int* ptr = NULL;`
- Biến mảng (Array Variables): Lưu trữ nhiều giá trị trong một biến duy nhất.
	`int numbers[] = {1, 2, 3, 4, 5};`
- Biến kích thước (Size Variables): Lưu trữ giá trị kích thước của các đối tượng trong bộ nhớ.
    ```size_t length = 10;```
- Biến không đổi (Constant Variables): Lưu trữ giá trị không thay đổi trong suốt thời gian chương trình chạy.
    ```const int MAX_VALUE = 100;```
- Biến từ khóa (Keyword Variables): Lưu trữ giá trị trùng với các từ khóa được định nghĩa trong ngôn ngữ C.
    ```int int = 5;```
- Biến từ xa (Extern Variables):Khai báo một biến đã được định nghĩa trong một tệp tin khác.
    ```extern int globalVar;```
- Biến có phạm vi tĩnh (Static Scope Variables): Lưu trữ giá trị trong suốt vòng đời của biến và chỉ có thể truy cập trong phạm vi của một hàm hoặc tệp tin.
    ```static int count = 0;```
- Biến hệ thống (System Variables): Lưu trữ thông tin đối với chương trình chạy, như số lượng tham số dòng lệnh và danh sách tham số.
    ```int argc; char** argv;```
- Biến môi trường (Environment Variables): Lưu trữ thông tin môi trường hệ thống như đường dẫn, biến cấu hình, v.v.
    `char* path = getenv("PATH");`
- Biến vô kiểu (Void Variables): Lưu trữ một địa chỉ bất kỳ và có thể chuyển đổi thành bất kỳ kiểu con trỏ nào.
	`void* ptr;`
- Biến hằng số từ xa (Extern Constant Variables): Khai báo một hằng số đã được định nghĩa trong một tệp tin khác.
    `extern const int MAX_VALUE;`
- Biến gần (Auto Variables): Được sử dụng để chỉ ra rằng một biến cục bộ tự động sẽ được tạo ra.
 	`auto int x = 5;`
- Biến trình tự (Sequence Variables): Chỉ định rằng một biến thường được truy cập nhanh chóng và thường xuyên.
    `register int counter = 0;`
- Biến quyền (Qualifier Variables): Đánh dấu biến có thể thay đổi mà không cần thông báo và không nên tối ưu hóa.
   	`volatile int status;`
- Biến tĩnh (Static Variables): Lưu trữ giá trị trong suốt vòng đời của chương trình và giá trị được duy trì ngay cả khi hàm hoặc khối lệnh kết thúc.
	```static int count = 0;```
- Biến tĩnh cục bộ (Local Static Variables): Lưu trữ giá trị trong suốt vòng đời của biến, nhưng chỉ có thể truy cập trong phạm vi của một hàm.
    ```C
    void function() {
        static int count = 0;
        // ...
    }
    ```
- Biến toàn cục (Global Variables): Khai báo ngoài hàm. Lưu trữ giá trị có thể truy cập từ bất kỳ đâu trong chương trình.
	```int globalVar = 10;```
- Biến cục bộ (Local Variables): Khai báo trong hàm. Lưu trữ giá trị chỉ có thể truy cập trong phạm vi của một hàm hoặc khối lệnh.
	```C
	void function() {
    	int localVar = 5;
   		// ...
	} 
	```
- Biến tên (Label Variables): Đánh dấu một vị trí trong mã chương trình để nhảy đến khi sử dụng lệnh goto.
    ```C
    goto label;
    // ...
    label:
        // ...
    ```
- Biến tham chiếu (Reference Variables): Lưu trữ một tham chiếu đến một biến đã tồn tại, cho phép thay đổi giá trị của biến qua tham chiếu.
    ```C
    int x = 10;
    int& ref = x;
    ```
- Biến hàm (Function Variables): Lưu trữ địa chỉ của một hàm và cho phép gọi hàm thông qua con trỏ.
    ```C
    int (*func_ptr)(int, int);
    int sum(int a, int b) {
        return a + b;
    }
    func_ptr = sum;
    ```
- Biến cấu trúc (Structure Variables): Lưu trữ các thành phần có liên quan vào một biến.
    ```
    struct Person {
        char name[20];
        int age;
    };
    struct Person p1;
	```
- Biến cấu trúc mở rộng (Extended Structure Variables): Lưu trữ các thành phần có liên quan vào một biến và mở rộng chức năng của cấu trúc.
    ```C
    struct Person {
        char name[20];
        int age;
    } p1;
    ```
- Biến liên kết (Union Variables): Lưu trữ giá trị của một thành phần trong một thời điểm.
    ```
    union Data {
        int x;
        float y;
    };
    union Data data;
    ```
- Biến liệt kê (Enumeration Variables): Lưu trữ một trong các giá trị được xác định trước từ một tập hợp các giá trị có tên.
    ```
    enum Color {
        RED,
        GREEN,
        BLUE
    };
	enum Color c = BLUE;
- Biến kiểu định danh (Typedef Variables): Tạo ra một tên mới cho một kiểu dữ liệu đã tồn tại để sử dụng dễ dàng hơn.
    ```C
    typedef int Integer;
    Integer number = 42;
	```
- Biến kiểu dữ liệu do người dùng định nghĩa (User-defined Data Type Variables): Định nghĩa và sử dụng kiểu dữ liệu tùy chỉnh trong ngôn ngữ C.
	```C
	typedef struct {
    	char name[20];
    	int age;
	} Person;
	Person p1; 
	```
### Khác nhau của static cục bộ và static toàn cục:
- Biến static cục bộ: Khi 1 biến cục bộ được khai báo với từ khóa static. Biến sẽ chỉ được khởi tạo 1 lần duy nhất và tồn tại suốt thời gian chạy chương trình. Giá trị của nó không bị mất đi ngay cả khi kết thúc hàm. Tuy nhiên khác với biến toàn cục có thể gọi trong tất cả mọi nơi trong chương trình, thì biến cục bộ static chỉ có thể được gọi trong nội bộ hàm khởi tạo ra nó. Mỗi lần hàm được gọi, giá trị của biến chính bằng giá trị tại lần gần nhất hàm được gọi.
- Biến static toàn cục: Biến toàn cục static sẽ chỉ có thể được truy cập và sử dụng trong File khai báo nó, các File khác không có cách nào truy cập được. 
</details>

<details>
  <summary>*Macro, Inline, Function</summary>

- **_Macro:_** Được xử lý bởi preprocessor
  - Thay thế đoạn code được khai báo macro vào bất cứ chỗ nào xuất hiện macro đó
  - VD: Preprocessor khi gặp bất kỳ lời gọi SUM(first+last) nào thì thay ngay bằng
  ```C
  #define SUM(a,b)     (a+b)
  ```
- **_Inline:_** Được xử lý bởi compiler
  - Được khai báo với từ khóa inline
  - Khi compiler thấy bất kỳ chỗ nào xuất hiện inline function, nó sẽ thay thế chỗ đó bởi định nghĩa của hàm đã được compile tương ứng. –> Phần được thay thế không phải code mà là đoạn code đã được compile
- **_Function:_** Khi thấy hàm được gọi, compiler sẽ phải lưu con trỏ chương trình PC hiện tại vào stack; chuyển PC tới hàm được gọi, thực hiện hàm đó xong và lấy kết quả trả về; sau đó quay lại vị trí ban đầu trong stack trước khi gọi hàm và tiếp tục thực hiện chương trình.
  - Như có thể thấy, các này khiến chương trình tốn thời gian hơn là chỉ cần thay thế đoạn code đã được compile (cách của inline function)

### So sánh Macro, Inline, Function:

- Macro đơn giản là chỉ thay thế đoạn code macro vào chỗ được gọi trước khi được biên dịch
- Inline thay thế đoạn mã code đã được biên dịch vào chỗ được gọi
- Hàm bình thường phải tạo một function call, lưu địa chỉ trước khi gọi hàm vào stack sau đó mới thực hiện hàm và sau cùng là quay trở về địa chỉ trên stack trước khi gọi hàm và thực hiện tiếp chương trình
- Macro khiến code trở nên dài hơn rất nhiều so với bình thường nhưng thời gian chạy nhanh.
- Hàm inline cũng khiến code dài hơn, tuy nhiên nó làm giảm thời gian chạy chương trình
- Hàm bình thường sẽ phải gọi function call nên tốn thời gian hơn inline function nhưng code ngắn gọn hơn.
</details>



<details>
  <summary>*Struct and Union</summary>

- Về mặt ý nghĩa, struct và union cơ bản giống nhau. Tuy nhiên, về mặt lưu trữ trong bộ nhớ, chúng có sự khác biệt rõ rệt như sau: - struct: Dữ liệu của các thành viên của struct được lưu trữ ở những vùng nhớ khác nhau. Do đó kích thước của 1 struct tối thiểu bằng kích thước các thành viên cộng lại tại vì còn phụ thuộc vào bộ nhớ đệm (struct padding). - Union : Dữ liệu các thành viên sẽ dùng chung 1 vùng nhớ. Kích thước của union được tính là kích thước lớn nhất của kiểu dữ liệu trong union. Việc thay đổi nội dung của 1 thành viên sẽ dẫn đến thay đổi nội dung của các thành viên khác.
</details>

<details>
  <summary>*Pointer</summary>
	
- Bộ nhớ RAM chứa rất nhiều ô nhớ, `mỗi ô nhớ có kích thước 1 byte`. Mỗi ô nhớ có địa chỉ duy nhất và địa chỉ này được đánh số từ 0 trở đi. Nếu `CPU 32bit` thì có `2^32 địa chỉ` có thể đánh cho các ô nhớ trong RAM.
	| Ô nhớ | 0 | 1 | ... | 2^32-2 | 2^32-1 |
  	|:-------:|:--------:|:--------:|---|:----------:|:--------:|
  	| Địa chỉ |0x00000000|0x00000001|...|0x0=fffffffe|0xffffffff|
	| Giá trị |          |     5    |...|     's'    |          |
	|   Biến  |          |     x    |...|    char    |          |
- Khi khai báo biến, trình biên dịch dành riêng một vùng nhớ với địa chỉ duy nhất để lưu biến. Trình biên dịch có nhiệm vụ liên kết địa chỉ ô nhớ đó với tên biến. Khi gọi tên biến, nó sẽ truy xuất tự động đến ô nhớ đã liên kết với tên biến để lấy dữ liệu. Các bạn phải luôn phân biệt giữa `địa chỉ bộ nhớ` và `dữ liệu được lưu trong đó`.
- Địa chỉ của biến bản chất cũng là một con số thường được biểu diễn ở `hệ cơ số 16`. Ta có thể sử dụng con trỏ (pointer) để lưu địa chỉ của các biến.
- ***Con trỏ(pointer):***
	- Trong ngôn ngữ C/C++, con trỏ (pointer) là những biến lưu trữ địa chỉ bộ nhớ của những biến khác.
	- Kích thước của các biến con trỏ có khác nhau không? Con trỏ chỉ lưu địa chỉ nên kích thước của mọi con trỏ là như nhau. Kích thước này phụ thuộc vào môi trường hệ thống máy tính:
		- `Môi trường Windows 32 bit: 4 bytes`
        - `Môi trường Windows 64 bit: 8 bytes`
### Các loại con trỏ:
- ***Con trỏ NULL:*** Con trỏ NULL là con trỏ lưu địa chỉ 0x00000000. Tức địa chỉ bộ nhớ 0, có ý nghĩa đặc biệt, cho biết con trỏ không trỏ vào đâu cả.
	```c
	int *p2; //con trỏ chưa khởi tạo, vẫn trỏ đến một vùng nhớ nào đó không xác định
	int *p3 = NULL; //con trỏ null không trỏ đến vùng nhớ nào
	int *p4 = null; // Lỗi "null" phải viết in hoa
	```
- ***Con trỏ đến con trỏ(pointer to pointer):*** Con trỏ này dùng để lưu địa chỉ của con trỏ khác.
	```c
	int x = 10;
    int *p1 = &x;     // Con trỏ p1 trỏ đến biến x và giá trị của p1 chỉnh là địa chỉ của biến x
    int **p2 = &p1;	 // Con trỏ p2 trỏ đến con trỏ p1 và lưu địa chỉ của con trỏ p1 vào p2

    printf("Giá trị của x: %d\n", *p1); //Giá trị của x: 10
    printf("Địa chỉ của x: %p\n", p1); //Địa chỉ của x: 0x7ffee2a697a8
    printf("Giá trị của x: %d\n", **p2); //Giá trị của x: 10
    printf("Địa chỉ của p1: %p\n", p2); //Địa chỉ của p1: 0x7ffee2a697a0
    ```

- **_Con trỏ hằng (Constant Pointers):_** Không thể thay đổi giá trị mà nó trỏ tới, nhưng có thể thay đổi địa chỉ mà nó trỏ tới.
  ```c
  int num = 10;
  const int *ptr = &num; //thay đổi được địa chỉ của num nhưng không thay đổi được giá trị '10' của num
  ```
- **_Con trỏ void (Void Pointers):_** Con trỏ void có thể trỏ tới bất kỳ kiểu dữ liệu nào, nhưng khi xuất ra giá trị thì phải ép kiểu.
  ```c
  int num = 10;
  float f = 3.14;
  void *ptr;
  ptr = &num;
  printf("num = %d\n",(int*)ptr);
  ptr = &f;
  printf("f = %f\n",(float*)ptr);
  ```
- **_Con trỏ hàm (Function Pointers):_** Dùng để lưu trữ và gọi các hàm thông qua con trỏ.

  ```c
  int add(int a, int b) {
  	return a + b;
  }
  int subtract(int a, int b) {
  	return a - b;
  }

  int main() {

  	int (*operation)(int, int) = add;
  	int result = operation(5, 3);
  	printf("Result: %d\n", result);

  	operation = subtract;
  	result = operation(5, 3);
  	printf("Result: %d\n", result);

  	return 0;
  }

  ```

- **_Con trỏ vào hàm (Pointers to Functions):_** Lưu trữ địa chỉ của một hàm cụ thể để gọi hàm thông qua con trỏ.

  ```c
  int add(int a, int b) {
  	return a + b;
  }
  int subtract(int a, int b) {
  	return a - b;
  }

  void performOperation(int a, int b, int (*operation)(int, int)) {
  	int result = operation(a, b);
  	printf("Result: %d\n", result);
  }

  int main() {
  	int a = 5, b = 3;

  	performOperation(a, b, add);
  	performOperation(a, b, subtract);

  	return 0;
  }

  ```

- **_Con trỏ hàm parameter (Function Pointer Parameters):_** Truyền một hàm như một tham số cho một hàm khác.

  ```c
  void greet() {
  	printf("Hello, World!\n");
  }

  void performAction(void (*action)()) {
  	action();
  }

  int main() {
  	performAction(greet);

  	return 0;
  }

  ```

### Lưu ý khi sử dụng con trỏ

- Khi khởi tạo con trỏ NULL: Chữ NULL phải viết hoa, viết thường null sẽ bị lỗi.
- Không nên sử dụng con trỏ khi chưa được khởi tạo: Kết quả tính toán có thể sẽ phát sinh những lỗi không lường trước được nếu chưa khởi tạo con trỏ.
- Sử dụng biến con trỏ sai cách.

</details>

<details>
  <summary>*Static and Extern</summary>
Static
	
- Static toàn cục: chỉ truy cập và sử dụng trong File khai báo nó, các File khác sẽ không thể truy cập được.
- Static cục bộ: chỉ khởi tạo 1 lần và tồn tại suốt thời thời gian chạy chương trình. Giá trị không mất đi khi kết thúc hàm, tuy nhiên biến static cục bộ chỉ có thể được gọi trong hàm khởi tạo nó, giá trị của biến chính bằng giá trị gần nhất mà nó được gọi.
- Ngoài ra, còn có extern để thông báo biến đã được khai báo ở file khác.

Extern

Biến extern được sử dụng khi một file cụ thể cần truy cập một biến từ file khác.
Để sử dụng được biến toàn cục ở một file khác, chúng ta phải khai báo lại biến và thêm từ khóa extern phía trước, để báo rằng biến này đã được khi báo ở file khác.

Cú pháp: extern <kiểu dữ liệu> <Tên Biến>;

</details>


##

### Ngôn ngữ C++
<details>
  <summary>*CLASS</summary>
### Khái niệm
> Class hay lớp là một mô tả trừu tượng **(abstract)** của nhóm các đối tượng **(object)** có cùng bản chất, ngược lại mỗi một đối tượng là một thể hiện cụ thể **(instance)** cho những mô tả trừu tượng đó. Một class trong C++ sẽ có các đặc điểm sau:  
> - Một class bao gồm các thành phần dữ liệu (thuộc tính hay property) và các phương thức (hàm thành phần hay method).
> - Class thực chất là một kiểu dữ liệu do người lập trình định nghĩa.
> - Trong C++, từ khóa class sẽ chỉ điểm bắt đầu của một class sẽ được cài đặt.
 
### Khai báo class và sử dụng class
   
```ruby
class Person {
public:
string firstName; // property
string lastName; // property
int age; // property
void fullname() { // method
cout << firstName << ' ' << lastName;
}
}
```
   
 ### Access modifiers & properties declaration
   
> ***Access modifier*** là phạm vi truy cập của các thuộc tính và phương thức sẽ được khai báo bên dưới nó. Có 3 phạm vi truy cập trong C++ là **public**, **private** và **protected**
> - Các thuộc tính và phương thức khai báo public thì có thể được truy cập trực tiếp thông qua instance của class đó. Các thuộc tính nên khai báo là public nếu bạn không có ràng buộc điều kiện trước khi gán (người dùng có thể  thoải mái gán giá trị) hoặc bạn không cần xử lý trước khi trả về giá trị thuộc tính.
> - Các thuộc tính private thường được sử dụng khi bạn không mong muốn người khác có thể tùy ý gán giá trị hoặc là bạn muốn xử lý trước khi trả về giá trị.
> - Đối với protected, các phương thức và thuộc tính chỉ có thể truy cập qua các class kế thừa nó hoặc chính nó.

### Method declaration
   
   > Phương thức cũng giống như một hàm bình thường. Nó có thể có hoặc không có tham số, không trả về giá trị và thậm chí là override hàm.
     Đối với phương thức thì có **hai cách** định nghĩa thi hành: định nghĩa thi hành trong lúc định nghĩa class và định nghĩa thi hành bên ngoài class.
 
   👉 **Định nghĩa thi hành bên trong class:**
```ruby
class Animal {
 public:
 string sound;
 void makeNoise() {
 cout << sound;
 }
};
```
   
   👉 **Định nghĩa thi hành bên ngoài class:**
```ruby
class Animal {
 public:
 string sound;
 void makeNoise();
};
void Animal::makeNoise() {
 cout << sound;
}
```

   👉 **Tham số truyền vào phương thức:**  
- Cách 1: Dặt tên trùng với thuộc tính Class bằng cách kết hợp toán tử :: và con trỏ _this_\
- Cách 2: Đặt tên khác với thuộc tính ( thường thêm dấu "_" trước tên tham số giống thuộc tính private
   
🔹 ***Con trỏ this*** : đề cập đến thể hiện hay instance của class đó, thông qua con trỏ this ta có thể truy cập đến các thuộc tính và phương thức.
   
🔹 ***Toán tử phạm vi*** : dùng để xác định phương thức hoặc thuộc tính được gọi từ Class nào.
   
### Constructor
> Constructor hay hàm dựng là một hàm đặc biệt, nó sẽ được gọi ngay khi chúng ta khởi tạo một object. Công dụng chính là khởi gán các thuộc tính
   
### Static member
> Static member hay thành viên tĩnh trong class C++ cũng tương tự như với static variable (biến tĩnh) trong function. Đối với function, sau khi thực hiện xong khối lệnh và thoát thì biến tĩnh vẫn sẽ không mất đi. Đối với class, thành viên tĩnh sẽ là thuộc tính dùng chung cho tất cả các đối tượng của class đó, cho dù là không có đối tượng nào tồn tại. Tức là bạn có thể khai báo nhiều object, mỗi object các thuộc tính của nó đều khác nhau nhưng riêng static thì chỉ có một và static member tồn tại trong suốt chương trình cho dù có hay không có object nào của nó hay nói ngắn gọn là dùng chung một biến static.

</details>

<details>
<summary>*OOP</summary>

### Khái niệm
> OOP Object - Oriented Programming là cách tư duy mới tiếp cận hướng đối tượng để giải quyết các vấn đề bằng máy tính. Là một mô hình dựa trên khái niệm về Class và Object. Nó được sử dụng để tách 1 chương trình thành các phần đơn giản hơn, có thể tái sử dụng.

### Các đặc tính của lập trình hướng đối tượng
> Có 4 đặc tính: Kế thừa, Trừu tượng, Đa hình và Đóng gói

👉 **Tính kế thừa / Inheritance**
- Có 3 loại kế thừa : public, private và protected
   
   > Có nghĩa là một Class có thể kế thừa lại Class trước đó. Class kế thừa được gọi là Class con hay còn gọi là _subclass_. Class được kế thừa gọi là class cha hay còn gọi là _superclass_. Ngoài ra còn có thể mở rộng thêm các thành phần kế thừa và bổ sung thêm các thành phần mới.
   
👉 **Tính trừu tượng / Abstraction**
- Chỉ cần biết kết quả chứ không quan tâm cách làm
   > Là một khả năng mà chương trình có thể bỏ qua sự phức tạp bằng cách tập trung vào cốt lõi của thông tin cần xử lý. Điều đó có nghĩa, bạn có thể xử lý một đối tượng bằng cách gọi tên một phương thức và thu về kết quả xử lý, mà không cần biết làm cách nào đối tượng đó được các thao tác trong class.

👉 **Tính đa hình / Polymorphism**
- Có thể đạt được đa hình theo kiểu ghi đè phương thức (Method Overriding) hoặc nạp chồng phương thức ( Method Overloading)
   > Là một khả năng mà một phương thức trong class có thể đưa ra các kết quả hoàn toàn khác nhau, tùy thuộc vào dữ liệu được xử lý.
   
👉 **Tính đóng gói / Encapsulation**
- Mỗi thuộc tính sẽ có phạm vi truy cập hay còn gọi là access modifier -> Private
   > Có ý nghĩa không cho phép người sử dụng các đối tượng thay đổi trạng thái nội tại của một đối tượng, mà chỉ có phương thức nội tại của đối tượng có thể thay đổi chính nó. Điều đó có nghĩa, dữ liệu và thông tin sẽ được đóng gói lại, giúp các tác động bên ngoài một đối tượng không thể làm thay đổi đối tượng đó, nên sẽ đảm bảo tính toàn vẹn của đối tượng, cũng như giúp dấu đi các dữ liệu thông tin cần được che giấu.

</details>

<details>

<summary>*Namespacce and Templete</summary>
   
### Namespace
   > Namespace là từ khóa trong C++ được sử dụng để định nghĩa một phạm vi nhằm mục đích phân biệt các hàm, lớp, biến, ... cùng tên trong các thư viện khác nhau. Thông thưognf ta hay dùng namespace "std" trong thư viện iostream

### Templete
   > Là một từ khóa trong C++, và là một kiểu dữ liệu trừu tượng tổng quát hóa cho các kiểu dữ liệu int, float, double, bool...
     Template trong C++ có **2 loại** đó là _ function template_ & _class template_.
     Template giúp người lập trình định nghĩa tổng quát cho hàm và lớp thay vì phải nạp chồng (overloading) cho từng hàm hay phương thức với những kiểu dữ liệu khác nhau.

</details>

<details>

<summary>*Virtual</summary>
   
> Là một hàm thành viên trong lớp cơ sở mà lớp dẫn xuất khi kế thừa cần ***phải định nghĩa lại***.
> Hàm ảo được sử dụng trong lớp cơ sở khi cần đảm bảo hàm ảo đó sẽ được định  nghĩa lại trong lớp dẫn xuất. Việc này rất cần thiết trong trường hợp con trỏ có  kiểu là lớp cơ sở trỏ đến _đối tượng của lớp dẫn xuất_ ( hàm dẫn xuất được coi là khốp với lớp cơ sở nếu có cùng tên, loại tham số 'cho dù có là const' và kiểu trả về của hàm trong lớpcơ sở. Các hàm như vậy được gọi là ghi đè (Overiding).
> Hàm ảo chỉ khác hàm thành phần thông thường khi được gọi từ một con trỏ. Sử  dụng hàm ảo khi muốn con trỏ đang trỏ tới đối tượng của lớp nào thì hàm thành phần của lớp đó sẽ được gọi mà không xem xét đến kiểu của con trỏ.
   
❗**Lưu ý**: Con trỏ của lớp cơ sở có thể chứa địa chỉ của đối tượng thuộc lớp dẫn xuất, nhưng ngược lại thì không được.
   
</details>

<details>

<summary>*Vector</summary>
   
> Giống như là mảng (array), vector trong C++ là một đối tượng dùng để chứa các đối  tượng khác, và các đối tượng được chứa này cũng được lưu trữ một cách liên tiếp  trong vector. Tuy nhiên, nếu như số lượng phần tử (size) của một mảng là cố định, thì ở vector, nó hoàn toàn có thể _thay đổi_ trong suốt quá trình làm việc của chương trình. 

📓 **Modifiers**
   1. **push_back()**: Hàm đẩy một phần tử vào vị trí sau cùng của vector. Nếu kiểu của đối tượng được truyền dưới dạng tham số trong push_back() không giống với kiểu 
của vector thì sẽ bị ném ra.
```ruby
ten-vector.push_back(ten-cua-phan-tu);
```
   
2. **assign()**: Nó gán một giá trị mới cho các phần tử vector bằng cách thay thế các  giá trị cũ.
```ruby  
ten-vector.assign(int size, int value);
```   
   
3. **pop_back()**: Hàm pop_back () được sử dụng để xóa đi phần tử cuối cùng một vector.
```ruby
ten-vector.pop_back();   
```  
   
4. **insert()**: Hàm này chèn các phần tử mới vào trước phần tử trước vị trí được trỏ bởi vòng lặp. Chúng ta cũng có thể chuyển một số đối số thứ ba, đếm số lần phần tử được chèn vào trước vị trí được trỏ.
```ruby
ten-vector.insert(position, value);   
```    
   
5. **erase()**: Hàm được sử dụng để xóa các phần tử tùy theo vị trí vùng chứa
```ruby
ten-vector.erase(position);

ten-vector.erase(start-position, end-position);   
```      
   
6. **emplace()**: Nó mở rộng vùng chứa bằng cách chèn phần tử mới vào
```ruby
ten-vector.emplace(ten-vector.position, element);   
```   
   
7. **emplace_back()**: Nó được sử dụng để chèn một phần tử mới vào vùng chứa vector, phần tử mới sẽ được thêm vào cuối vector
```ruby
ten-vector.emplace_back(value);   
```    
   
8. **swap()**: Hàm được sử dụng để hoán đổi nội dung của một vector này với một vector khác cùng kiểu. Kích thước có thể khác nhau.
```ruby
ten-vector-1.swap(ten-vector-2);   
```      
   
9. **clear()**: Hàm được sử dụng để loại bỏ tất cả các phần tử của vùng chứa vector
```ruby
ten-vector.clear();  
``` 

</details>
