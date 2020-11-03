import fs from 'fs';
import path from 'path';
import { Challenge, ChallengeFile } from '../types';
import challengeDatas from '../challenge-datas';
import {
  paths,
  config,
  createChallengeUrl,
  createSourceCodeUrl
} from '../config';

interface LevelDocument {
  [key: string]: { [key: string]: Challenge[] };
}

const levelDocument: LevelDocument = {};

function getChallengeFiles(): ChallengeFile[] {
  const challengeFiles: ChallengeFile[] = [];

  fs.readdirSync(paths.challenges).forEach((directoryName) => {
    fs.readdirSync(path.resolve(paths.challenges, directoryName)).forEach((fileName) => {
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
    case 'py':
      return 'Python';
    default:
      throw new Error(`${extension} is undefined extension.`);
  }
}

function saveLevelDocs(): void {
  if (!fs.existsSync(paths.levelDocs)) {
    fs.mkdirSync(paths.levelDocs);
  }

  Object.keys(levelDocument).forEach((mainLevel) => {
    const lines: string[] = [];

    config.levelDocsOrder.forEach((subLevel) => {
      if (!(subLevel in levelDocument[mainLevel])) {
        return;
      }

      lines.push(`## ${mainLevel} ${subLevel}`);

      levelDocument[mainLevel][subLevel].forEach((challengeData) => {
        const id = challengeData.id;
        const title = challengeData.title;
        const extension = challengeData.extension;
        const tags = challengeData.tags;
        const languageName = getLanguageName(extension);

        lines.push(`* [${title}](${createChallengeUrl(id)}) (${id}) - [${languageName}](${createSourceCodeUrl(id, extension)})`);
        lines.push(`  - ${tags.join(', ')}`);
      });
    });

    const fileName = `${config.levelDocsPrefix + mainLevel.toUpperCase()}.md`;
    fs.writeFileSync(path.resolve(paths.levelDocs, fileName), lines.join('\n'), { encoding: 'utf8' });
  });
}

(() => {
  getChallengeFiles().forEach((challengeFile) => {
    if (!(challengeFile.id in challengeDatas)) {
      throw new Error(`The data of challenge ${challengeFile.id} does not exist. Please add it to \`challenge-datas.ts\`.`);
    }

    updateLevelDocument({ ...challengeFile, ...challengeDatas[challengeFile.id] });
  });

  saveLevelDocs();
})();