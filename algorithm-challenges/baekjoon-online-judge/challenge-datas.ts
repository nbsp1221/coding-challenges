import { ChallengeData } from './types';

const challengeDatas: { [key: number]: ChallengeData } = {
  1021:  { title: '회전하는 큐', level: 'Silver IV', tags: ['Double-ended queue'] },
  1049:  { title: '기타줄', level: 'Silver IV', tags: ['Implementation'] },
  1063:  { title: '킹', level: 'Silver V', tags: ['Simulation'] },
  1094:  { title: '막대기', level: 'Silver V', tags: ['Implementation'] },
  1107:  { title: '리모컨', level: 'Gold V', tags: ['Brute-force search'] },
  1292:  { title: '쉽게 푸는 문제', level: 'Silver IV', tags: ['Implementation'] },
  1389:  { title: '케빈 베이컨의 6단계 법칙', level: 'Silver I', tags: ['BFS', 'Graph theory'] },
  1476:  { title: '날짜 계산', level: 'Silver V', tags: ['Implementation'] },
  1541:  { title: '잃어버린 괄호', level: 'Silver II', tags: ['Greedy algorithm'] },
  1654:  { title: '랜선 자르기', level: 'Silver III', tags: ['Binary search'] },
  1676:  { title: '팩토리얼 0의 개수', level: 'Silver III', tags: ['Mathematics'] },
  1681:  { title: '줄 세우기', level: 'Bronze II', tags: ['Implementation'] },
  1699:  { title: '제곱수의 합', level: 'Silver III', tags: ['Dynamic programming', 'Mathematics'] },
  1717:  { title: '집합의 표현', level: 'Gold IV', tags: ['Disjoint set'] },
  1964:  { title: '오각형, 오각형, 오각형…', level: 'Bronze III', tags: ['Mathematics'] },
  1992:  { title: '쿼드 트리', level: 'Silver I', tags: ['Divide and conquer', 'Recursion'] },
  2010:  { title: '플러그', level: 'Bronze III', tags: ['Mathematics'] },
  2133:  { title: '타일 채우기', level: 'Silver II', tags: ['Dynamic programming'] },
  2193:  { title: '이친수', level: 'Silver III', tags: ['Dynamic programming'] },
  2217:  { title: '로프', level: 'Silver IV', tags: ['Greedy algorithm'] },
  2468:  { title: '안전 영역', level: 'Silver I', tags: ['Brute-force search', 'DFS'] },
  2580:  { title: '스도쿠', level: 'Gold IV', tags: ['Backtracking'] },
  2740:  { title: '행렬 곱셈', level: 'Bronze I', tags: ['Mathematics'] },
  2776:  { title: '암기왕', level: 'Silver III', tags: ['Hash set'] },
  2935:  { title: '소음', level: 'Bronze III', tags: ['Implementation'] },
  2953:  { title: '나는 요리사다', level: 'Bronze III', tags: ['Implementation'] },
  3059:  { title: '등장하지 않는 문자의 합', level: 'Bronze II', tags: ['Implementation'] },
  5355:  { title: '화성 수학', level: 'Bronze II', tags: ['Implementation'] },
  5430:  { title: 'AC', level: 'Silver II', tags: ['Double-ended queue'] },
  5525:  { title: 'IOIOI', level: 'Silver II', tags: ['Implementation'] },
  5717:  { title: '상근이의 친구들', level: 'Bronze III', tags: ['Implementation'] },
  6064:  { title: '카잉 달력', level: 'Silver I', tags: ['Mathematics'] },
  7567:  { title: '그릇', level: 'Bronze II', tags: ['Implementation'] },
  7569:  { title: '토마토', level: 'Silver I', tags: ['BFS'] },
  7662:  { title: '이중 우선순위 큐', level: 'Gold V', tags: ['Tree'] },
  8320:  { title: '직사각형을 만드는 방법', level: 'Bronze III', tags: ['Mathematics'] },
  9019:  { title: 'DSLR', level: 'Gold V', tags: ['BFS'] },
  9205:  { title: '맥주 마시면서 걸어가기', level: 'Silver I', tags: ['DFS', 'Graph theory'] },
  9295:  { title: '주사위', level: 'Bronze III', tags: ['Implementation'] },
  9375:  { title: '패션왕 신해빈', level: 'Silver III', tags: ['Hash table'] },
  9465:  { title: '스티커', level: 'Silver II', tags: ['Dynamic programming'] },
  9536:  { title: '여우는 어떻게 울지?', level: 'Silver V', tags: ['Implementation'] },
  9655:  { title: '돌 게임', level: 'Silver V', tags: ['Dynamic programming'] },
  9656:  { title: '돌 게임 2', level: 'Silver IV', tags: ['Dynamic programming'] },
  9657:  { title: '돌 게임 3', level: 'Silver III', tags: ['Dynamic programming'] },
  9658:  { title: '돌 게임 4', level: 'Silver I', tags: ['Dynamic programming'] },
  9659:  { title: '돌 게임 5', level: 'Gold V', tags: ['Game theory'] },
  9660:  { title: '돌 게임 6', level: 'Gold V', tags: ['Game theory'] },
  9661:  { title: '돌 게임 7', level: 'Gold II', tags: ['Game theory', 'Mathematics'] },
  9663:  { title: 'N-Queen', level: 'Gold V', tags: ['Backtracking'] },
  10026: { title: '적록색약', level: 'Gold V', tags: ['DFS', 'Recursion'] },
  10102: { title: '개표', level: 'Bronze II', tags: ['Implementation'] },
  11047: { title: '동전 0', level: 'Silver I', tags: ['Greedy algorithm'] },
  11055: { title: '가장 큰 증가 부분 수열', level: 'Silver II', tags: ['Dynamic programming'] },
  11057: { title: '오르막 수', level: 'Silver I', tags: ['Dynamic programming'] },
  11286: { title: '절댓값 힙', level: 'Silver I', tags: ['Priority queue'] },
  11399: { title: 'ATM', level: 'Silver III', tags: ['Greedy algorithm', 'Sorting'] },
  11403: { title: '경로 찾기', level: 'Silver I', tags: ['DFS', 'Graph theory'] },
  11536: { title: '줄 세우기', level: 'Silver V', tags: ['Implementation'] },
  11816: { title: '8진수, 10진수, 16진수', level: 'Bronze I', tags: ['Implementation'] },
  14425: { title: '문자열 집합', level: 'Silver III', tags: ['Hash set'] },
  14500: { title: '테트로미노', level: 'Gold V', tags: ['Brute-force search'] },
  14501: { title: '퇴사', level: 'Silver IV', tags: ['Dynamic programming'] },
  15486: { title: '퇴사 2', level: 'Silver II', tags: ['Dynamic programming'] },
  17219: { title: '비밀번호 찾기', level: 'Silver IV', tags: ['Hash table'] },
  17626: { title: 'Four Squares', level: 'Silver V', tags: ['Dynamic programming'] },
  18870: { title: '좌표 압축', level: 'Silver II', tags: ['Coordinate compression', 'Sorting'] }
};

export default challengeDatas;