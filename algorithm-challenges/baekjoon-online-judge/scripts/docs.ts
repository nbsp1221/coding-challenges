import fs from 'fs';
import path from 'path';
import { Challenge, ChallengeFile } from '../types';
import challengeDatas from '../challenge-datas';

interface LevelDocument {
  [key: string]: { [key: string]: Challenge[] };
}

const config = {
  challengeUrl: 'https://www.acmicpc.net/problem/',
  sourceCodeUrl: 'https://github.com/nbsp1221/algorithm/blob/master/algorithm-challenges/baekjoon-online-judge/challenges/'
} as const;

const rootPath = path.resolve(__dirname, '../');
const challengesPath = path.resolve(rootPath, 'challenges');
const levelPath = path.resolve(rootPath, 'level');
const levelDocument: LevelDocument = {};

function getChallengeFiles(): ChallengeFile[] {
  const challengeFiles: ChallengeFile[] = [];

  fs.readdirSync(challengesPath).forEach((directoryName) => {
    fs.readdirSync(path.resolve(challengesPath, directoryName)).forEach((fileName) => {
      const splitted = fileName.split('.');
      challengeFiles.push({ id: parseInt(splitted[0], 10), extension: splitted[1] });
    });
  });

  return challengeFiles;
}

function updateLevelDocument(challenge: Challenge): void {
  const splitted = challenge.level.split(' ');
  const mainLevel = splitted[0];
  const subLevel = splitted[1];

  if (!(mainLevel in levelDocument)) {
    levelDocument[mainLevel] = {};
  }

  if (!(subLevel in levelDocument[mainLevel])) {
    levelDocument[mainLevel][subLevel] = [];
  }

  levelDocument[mainLevel][subLevel].push(challenge);
}

function getLanguageName(extension: string): string {
  switch (extension) {
    case 'cpp':
      return 'C++';
    default:
      throw new Error(`${extension} is undefined extension.`);
  }
}

function saveLevelDocument(): void {
  if (!fs.existsSync(levelPath)) {
    fs.mkdirSync(levelPath);
  }

  Object.keys(levelDocument).forEach((mainLevel) => {
    const lines: string[] = [];

    Object.keys(levelDocument[mainLevel]).forEach((subLevel) => {
      lines.push(`## ${mainLevel} ${subLevel}`);

      levelDocument[mainLevel][subLevel].forEach((challengeData) => {
        const id = challengeData.id;
        const title = challengeData.title;
        const extension = challengeData.extension;
        const tags = challengeData.tags;
        const languageName = getLanguageName(extension);

        lines.push(`* [${title}](${config.challengeUrl}${id}) (${id}) - [${languageName}](${config.sourceCodeUrl}${Math.floor(id / 1000) * 1000}/${id}.${extension})`);
        lines.push(`  - ${tags.join(', ')}`);
      });
    });

    fs.writeFileSync(path.resolve(levelPath, mainLevel.toLowerCase() + '.md'), lines.join('\n'), { encoding: 'utf8' });
  });
}

(() => {
  getChallengeFiles().forEach((challengeFile) => {
    if (!(challengeFile.id in challengeDatas)) {
      throw new Error(`The data of challenge ${challengeFile.id} does not exist. Please add it to \`challenge-datas.ts\`.`);
    }

    updateLevelDocument({ ...challengeFile, ...challengeDatas[challengeFile.id] });
  });

  saveLevelDocument();
})();