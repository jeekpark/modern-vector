# 모던 C++ 벡터(선행대수, 해석기하) 템플릿 클래스


## Overview:
- 이 레포지토리는 모던 C++ 기반의 벡터 템플릿 클래스를 설명합니다.
- C++의 최신 기능을 활용하여 효율적이고 유용한 클래스를 구현되었습니다.
- 벡터 간의 기본적인 수학적 연산을 지원합니다.

## Feature:
- **모던 C++ 구현**: 최신 C++ 표준을 활용하여 효율성과 가독성을 높였습니다.
- **템플릿 기반 설계**: 다양한 데이터 타입을 지원하는 벡터 연산을 가능하게 합니다.

## Modern C++:
- 사용된 기능은 다음과 같습니다.
    - ```[[nodiscard]]```: 프로그래머의 실수를 방지하는 키워드. 반환값을 무시하지 못하도록 컴파일타임에 검사합니다.
        ```cpp
        [[nodiscard]] int returnFive();

        int main()
        {
            returnFive(); // Error. 
            int num = returnFive(); // OK
        }
        ```
    - ```constexpr```: 컴파일 타임에 상수 값을 생성하는 변수나 함수를 정의하는 키워드
        ```cpp
        constexpr int square(int n)
        {
            return n * n;
        }


        int main()
        {
            // 컴파일 시간에 계산됨
            constexpr int val = square(5); 
        
            // 런타임에 계산됨.
            int runtime_val = 6;
            cout << square(runtime_val) << endl;

            // 런타임에 계산됨
            int in;
            cin >> in;
            int some = square(in);

            // 컴파일 오류
            constexpr int thing = square(in); 
        }
        ```
    - ```explicit```: 생성자가 암시적 타입 변환을 허용하지 않도록 지정하는 키워드
        ```cpp
        class MyNumber 
        {
        public:
            explicit MyNumber(int num); // explicit 생성자
        private:
            int number;
        };

        int main()
        {
            MyNumber num1(10); // 정상: 직접 초기화
            MyNumber num2 = 20; // 오류: explicit 때문에 암시적 변환 금지
            MyNumber num3 = MyNumber(30); // 정상: 명시적 변환
        }
        ```
    - ```using 별칭```: 기존 타입에 대한 새로운 이름을 정의하여 코드의 가독성을 향상시키는 타입 별칭 선언
        ```cpp
        using Vec2f = Vector2<float>;
        using Vec2i = Vector2<int>;

        int main()
        {
            Vec2f v1(1.f, 2.f);
            Vec2i v2(3, 4);
        }
        ```

