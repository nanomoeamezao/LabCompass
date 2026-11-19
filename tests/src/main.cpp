#include "helper/roompresethelper.h"
#include "tests/labyrinthdata/labyrinthdataloadtest.h"
#include "tests/labyrinthdata/labyrinthdataroomistrialtest.h"
#include "tests/labyrinthmodel/labyrinthmodelpropertiestest.h"
#include "tests/testdataavailabletest.h"
#include "tests/worker/logwatchertest.h"
#include <QCoreApplication>
#include <QTest>
#include <memory>

int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);
    Q_INIT_RESOURCE(common);
    RoomPresetHelper::instance = new RoomPresetHelper();

    if (int r = QTest::qExec(std::make_unique<TestDataAvailableTest>().get(), argc, argv)) {
        return r;
    }

    int result = QTest::qExec(std::make_unique<LabyrinthDataLoadTest>().get(), argc, argv);
    result |= QTest::qExec(std::make_unique<LabyrinthDataRoomIsTrialTest>().get(), argc, argv);
    result |= QTest::qExec(std::make_unique<LabyrinthModelPropertiesTest>().get(), argc, argv);
    result |= QTest::qExec(std::make_unique<LogWatcherTest>().get(), argc, argv);
    return result;
}
