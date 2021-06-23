//
//  SettingsViewModel.swift
//  ZenIDDemo
//
//  Created by Libor Polehna on 22.06.2021.
//  Copyright © 2021 Trask, a.s. All rights reserved.
//

import Foundation


final class SettingsViewModel {
    
    lazy var sections: [TableViewSectionViewModel] = {
        [
            TableViewSectionViewModel(
                title: nil,
                cells: [
                    BasicTableCellController(viewModel: .init(title: NSLocalizedString("settings-filter", comment: ""), action: { [weak self] in
                        self?.coordinator.settingsOpenDocumentsFilter()
                    }))
                ]
            )
        ]
    }()
    
    private let coordinator: SettingsCoordinable
    
    init(coordinator: SettingsCoordinable) {
        self.coordinator = coordinator
    }
    
    func finish() {
        coordinator.settingsDidFinish()
    }
    
}
