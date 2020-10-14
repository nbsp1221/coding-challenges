import path from 'path';

const rootPath = __dirname;
const resolvePath = (relativePath: string): string => path.resolve(rootPath, relativePath);

export const paths = {
  root: rootPath,
  challenges: resolvePath('challenges'),
  levelDocs: rootPath
} as const;

export const config = {
  levelDocsPrefix: 'LEVEL_',
  levelDocsOrder: ['V', 'IV', 'III', 'II', 'I']
} as const;

export function createChallengeUrl(id: number): string {
  return `https://www.acmicpc.net/problem/${id}`;
}

export function createSourceCodeUrl(id: number, extension: string): string {
  return `https://github.com/nbsp1221/algorithm/blob/master/algorithm-challenges/baekjoon-online-judge/challenges/${Math.floor(id / 1000) * 1000}/${id}.${extension}`;
}